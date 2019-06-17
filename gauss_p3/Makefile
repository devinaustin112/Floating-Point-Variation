default: gauss par_gauss

gauss: gauss.c timer.h
	gcc -g -O2 --std=c99 -Wall -o gauss gauss.c

par_gauss: par_gauss.c timer.h
	gcc -g -O2 --std=c99 -fopenmp -Wall -o par_gauss par_gauss.c

clean:
	rm -f gauss par_gauss

