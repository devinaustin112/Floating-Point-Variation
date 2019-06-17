#!/bin/bash

./clean.sh
./build.sh

rm -rf out

echo "Expected:"
./mg.A.x_ser | grep "L2 Norm is "

for i in {1..100} 
do
    OMP_NUM_THREADS=16 ./mg.A.x_omp | grep "L2 Norm is " >>out
done

../analysis.rb out
