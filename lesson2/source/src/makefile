DIR=$(shell pwd)
STR=$(shell echo $(DIR) | sed 's/src/include/')
CC=gcc
CFLAGS=-c -Wall -std=c99 -I$(STR)

all: main

main : main.o cmp.o
	$(CC) main.o cmp.o -o main

%.o : %.c
	$(CC) $(CFLAGS) $< -c

clean :
	rm -rf *.o main