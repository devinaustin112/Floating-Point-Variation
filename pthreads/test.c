/**
 * A demonstration of floating-point non-associativity.
 */

#include <stdio.h>
#include <stdlib.h>

double num;

void parallel(int rank)
{
    for (int x = 0; x < 100; x ++){
        if (rank % 2 == 0) {
            num += 0.1;
        } else {
            num += 0.3;
        }
    }
}

int main(int argc, char* argv[])
{
    num = 0.2;

    for(int x = 0; x < NUM_THREADS; x++) {
        parallel(x);
    }

    // print num
    printf("%.17f\n", num);

    return EXIT_SUCCESS;
}


