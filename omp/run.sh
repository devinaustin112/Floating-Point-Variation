#!/bin/bash

make clean
make

rm -rf out

echo "Expected:"
./test_ser

for i in {1..1000} 
do
    ./test >> out
done

../analysis.rb out
