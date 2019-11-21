CC=gcc
CFLAGS=-c -Wall -std=c99

all: mathlib

mathlib : mathlib.o
	ar rc libmathlib.a mathlib.o
	ranlib libmathlib.a

%.o : %.c
	$(CC) $(CFLAGS) $< -c

clean :
	rm -rf *.o