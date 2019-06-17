/**
 * An attempt to demonstrate floating-point non-associativity using OMP.
 */

#include <stdio.h>
#include <stdlib.h>

#ifdef _OPENMP
#include <omp.h>
#endif

int main(int argc, char* argv[])
{
    double num = 0.2;

#   pragma omp parallel for
    for (int x = 0; x < 1600; x ++){
        if (x % 2 == 0) {
#           pragma omp critical
            num += 0.1;
        } else {
#           pragma omp critical
            num += 0.3;
        }
    }
   
    // print num
    printf("%.17f\n", num);

    return EXIT_SUCCESS;
}


