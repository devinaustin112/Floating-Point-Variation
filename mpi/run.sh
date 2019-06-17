#!/bin/bash

make clean && make
rm -rf out

echo "Expected: "
./test 128

for i in {1..1000} 
do
	salloc -Q -n 8 mpirun ./test 128 >> out
done

../analysis.rb out 
