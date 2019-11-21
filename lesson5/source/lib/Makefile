DIR=$(shell pwd)
CC=gcc
CFLAGS=-c -Wall -std=c99 -fPIC

all: mathlib

mathlib : mathlib.o
	$(CC) -shared -o mathlib.so mathlib.o

%.o : %.c
	$(CC) $(CFLAGS) $< -c

clean :
	rm -rf *.o