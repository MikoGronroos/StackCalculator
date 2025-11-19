CC=gcc
CFLAGS=-I

stackcalculator: main.c shuntingYardAlgorithm.c stack.c calculate.c
	$(CC) -o a main.c shuntingYardAlgorithm.c stack.c calculate.c
