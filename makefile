CC=gcc
CFLAGS=-c -Wall -std=c99

all: main

main : main.o cmp.o
	$(CC) main.o cmp.o -o main

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

cmp.o : cmp.c
	$(CC) $(CFLAGS) -c cmp.c

clean :
	rm -rf *.o main