#!/bin/bash
cd src

#../sys/setparams mg A
gfortran -c  -O -fopenmp print_results.f
gfortran -c  -O -fopenmp randi8.f
gfortran -c  -O -fopenmp timers.f
cc  -c  -O  -o wtime.o wtime.c
gfortran -c  -O -fopenmp mg.f
gfortran -O -fopenmp -o ../mg.A.x_omp mg.o print_results.o randi8.o timers.o wtime.o


#../sys/setparams mg A
gfortran -c  -O print_results.f
gfortran -c  -O randi8.f
gfortran -c  -O timers.f
cc  -c  -O  -o wtime.o wtime.c
gfortran -c  -O mg.f
gfortran -O -o ../mg.A.x_ser mg.o print_results.o randi8.o timers.o wtime.o


