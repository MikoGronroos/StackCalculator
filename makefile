CC=gcc
CFLAGS=-I

stackcalculator: main.c shuntingYardAlgorithm.c stack.c
	$(CC) -o stackcalculator main.c shuntingYardAlgorithm.c stack.c
