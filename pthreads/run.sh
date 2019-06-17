#!/bin/bash

make clean
make

rm -f out

echo "Expected:"
./test

for i in {1..1000} 
do
	./par_test >> out
done

../analysis.rb out
