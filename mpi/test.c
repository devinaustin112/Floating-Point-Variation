#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

typedef unsigned long count_t;

double *nums;
double *sum;
int mpi_rank;
int mpi_size;
count_t global_n;


bool parse_command_line(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: %s <n> \n", argv[0]);
        return false;
    } else {
        global_n = strtol(argv[1], NULL, 10);
    }
    return true;

}

void shuffle(double *array, size_t n)
{
    
    if (n > 1) 
    {
        size_t i;
        srand(time(0));
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = rand() % (i+1);
          double t = array[j];
          array[j] = array[i];
          array[i] = t;
          
        }
        
    }

}


void randomize() 
{

    
   double *temp = (double*)calloc(global_n, sizeof(double));
   if (mpi_rank == 0) 
   {
	srand(42);
        for (count_t i = 0; i < global_n; i++)
        {
		temp[i] = (rand() % 100) / 10000.00;
     //		printf("temp[%d] = %f\n", i, temp[i]);
        }

   }
   
   shuffle(temp, global_n);
   //printf("%f index\n", temp[0]);   
   MPI_Scatter(temp, global_n/mpi_size, MPI_DOUBLE, nums, global_n/mpi_size, MPI_DOUBLE, 0, MPI_COMM_WORLD);
   

   free(temp); 


}

void totalSum()
{
   
   MPI_Reduce(nums, sum, global_n / mpi_size, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

}


int main(int argc, char* argv[])
{

    if (!parse_command_line(argc, argv)) {
        printf("exiting\n");
	exit(EXIT_FAILURE);
    }

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &mpi_size);

    int testing = global_n / mpi_size;
    //printf("%d testing\n", testing);

    

    nums = (double*)calloc(testing, sizeof(double));
    sum = (double*)calloc(testing, sizeof(double));

    memset(nums, 0, sizeof(double));
    memset(sum, 0, sizeof(double));
    if (nums == NULL)
    {
        fprintf(stderr, "Out of memory");
        exit(EXIT_FAILURE);

    }
    
    randomize();
    MPI_Barrier(MPI_COMM_WORLD);    

    totalSum();
    
    double total = 0;
//    printf("%ld size of sum\n", sizeof(nums)/sizeof(double));
    if (mpi_rank ==0) {
    for (int i = 0; i < global_n/mpi_size; i++)
    {
//       printf("%f sum\n", sum[i]);
       total += sum[i];

    }
    }
    MPI_Finalize();
    free(nums);
    free(sum);
    if (mpi_rank == 0) {
    printf("%.17f\n", total);
    }    
    return EXIT_SUCCESS;
}
