/**
 * A demonstration of floating-point non-associativity.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int thread_count;               // thread count
double num;
pthread_mutex_t num_mutex = PTHREAD_MUTEX_INITIALIZER;

void* parallel(void* arg)
{
    int rank = (int) arg; 

    for (int x = 0; x < 100; x ++){
        if (rank % 2 == 0) {
            pthread_mutex_lock(&num_mutex);
            num += 0.1;
        } else {
            pthread_mutex_lock(&num_mutex);
            num += 0.3;
        }
        pthread_mutex_unlock(&num_mutex);
    }

    return NULL;
}

int main(int argc, char* argv[])
{
    thread_count = NUM_THREADS;

    // simulate dart throws (TODO: spawn multiple threads)
    pthread_t *threads;
    threads = malloc(sizeof(pthread_t)*thread_count);

    num = 0.2;

    for(int x = 0; x < thread_count; x++) {
        pthread_create(&threads[x], NULL, parallel, (void*)x);
    }

    for(int x = 0; x < thread_count; x++) {
        pthread_join(threads[x], NULL);
    }
    
    // print num
    printf("%.17f\n", num);

    // clean up
    free(threads);
    pthread_mutex_destroy(&num_mutex);
    return EXIT_SUCCESS;
}


