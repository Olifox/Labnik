CC=gcc
CFLAGS=-c -Wall -std=c99

all: main

main : main.o
	$(CC) main.o -o main

%.o : %.c
	$(CC) $(CFLAGS) $< -c

clean :
	rm -rf *.o main