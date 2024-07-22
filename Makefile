.PHONY: main

all: main chbase
	gcc -g main.o chbase.o -o main -lm
main:
	gcc -g -c main.c

chbase:
	gcc -g -c chbase.c chbase.h

