CFLAGS=-g -O2 -Wall --std=c99
TARGETS=test test_ser

all: $(TARGETS)

test: test.c
	gcc $(CFLAGS) -fopenmp -o $@ $<

test_ser: test.c
	gcc $(CFLAGS) -Wno-unknown-pragmas -o $@ $<

clean:
	rm -f $(TARGETS)

