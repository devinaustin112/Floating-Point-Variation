#!/bin/bash

echo "Running OpenMP example"
cd omp
srun ./run.sh
cd ..

echo "Running pthreads example"
cd pthreads
srun ./run.sh
cd ..

echo "Running MPI example (~ 1 min)"
cd mpi
./run.sh
cd ..

echo "Running MG benchmark (~ 1 min)"
cd mg
./run.sh
cd ..

