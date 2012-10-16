# Makefile for sorting algorithms

CC = g++
FLAGS = -g -O0 -Wall
OBJS = Sorting.o main.o

sorting: $(OBJS)
	$(CC) $(FLAGS) bin/*.o -o bin/sorting

Sorting.o: Sorting.cpp
	$(CC) $(FLAGS) -c Sorting.cpp -o bin/$@

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp -o bin/$@

.PHONY: clean
clean:
	rm -f bin/sorting
	rm -f bin/*.o
