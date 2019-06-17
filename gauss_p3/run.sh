#!/bin/bash

if [ "$#" -eq 0 ]
then
    echo "usage: <num_trials>"
    exit
fi

#anywhere from 1 to 16
TRIALS=$1

if (( TRIALS > 16 || TRIALS < 1 ))
then
    echo "Trials must be between 1 and 16 inclusive"
    exit
fi

SIZE=1000
ARGS=""

make clean
make

echo "SERIAL:"
srun ./gauss $ARGS "$SIZE"

echo "PARALLEL:"
#OMP_NUM_THREADS=1  srun -N $TRIALS ./par_gauss $ARGS "$SIZE"
#OMP_NUM_THREADS=2  srun -N $TRIALS ./par_gauss $ARGS "$SIZE"
OMP_NUM_THREADS=4  srun -N $TRIALS ./par_gauss $ARGS "$SIZE"
OMP_NUM_THREADS=8  srun -N $TRIALS ./par_gauss $ARGS "$SIZE"
OMP_NUM_THREADS=16 srun -N $TRIALS ./par_gauss $ARGS "$SIZE"
