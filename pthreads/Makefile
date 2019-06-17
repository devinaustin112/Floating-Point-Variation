CFLAGS=-g -O2 -Wall --std=c99 -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast -DNUM_THREADS=16
TARGETS=test par_test

all: $(TARGETS)

test: test.c
	gcc $(CFLAGS) -o $@ $<

par_test: par_test.c
	gcc $(CFLAGS) -o $@ $< -lpthread

clean:
	rm -f $(TARGETS)

