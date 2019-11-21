DIR=$(shell pwd)
STR=$(shell echo $(DIR) | sed 's/src/lib/')
CC=gcc
CFLAGS=-c -Wall -std=c99 -I$(STR)

all: main

main : main.o
	$(CC) main.o -L$(STR) -lmathlib -o main

%.o : %.c
	$(CC) $(CFLAGS) $< -c

clean :
	rm -rf *.o main