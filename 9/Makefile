CC=gcc
CFLAGS=-g -Wall

all: lab9 function.o

lab9: function.o
	$(CC)$(CFLAGS) function.o lab9.c -o lab9 -lm

function.o:
	$(CC)$(CFLAGS) -c function.c

clean:
	sudo rm function.o lab9
