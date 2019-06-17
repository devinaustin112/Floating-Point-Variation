# FPVariation
FPVariation research project for CS470 sp'19 (https://github.com/logangregorym/FPVariation)

## How to run the tests
There are 4 different tests in this repository, each contained in its own folder. There
is a top level "run_all.sh" which can be used to run the pthreads, omp and mg tests. 
The gauss benchmark has not been compleatly tested, but can be run with the script to 
see the effect of different thread counts on variability.

## About the tests

It is important to note that these examples do not include any data races. All critical
sections are properly implemented so that only one thread can access the shared variable
at a time. The variance that we observe in the floating point numbers is solely due to
the non-associativity of IEEE floating point numbers.

### pthreads
  - A fairly simple test using pthreads which adds floating-point numbers together and
    generates clear variability. This test is fully functional and results can be seen
    by running the "run.sh" script.

### omp
  - This is the exact same test as v2, but uses OMP instead of pthreads. This test is
    fully functional and results can be seen by running the "run.sh" script.

### mpi
  - A test using MPI which produces some floating-point variability. This test is fully
    functional and results can be seen by running the "run.sh" script.

### gauss_p3 
  - This is from our 3rd project in CS470 which closely resembles the popular LINPACK
    benchmark used in ranking the worlds fastest supercomputers. is This test is still
    a work in progress. We have noticed some weird behavior where at different problem
    sizes some thread counts produce variability while others do not.

### mg
  - Part of the NAS parallel Benchmark suite. We run MG with the class size A which
    takes about one second per run.
