# Makefile for compute poly program

CC = g++
FLAGS = -g -O0 -Wall
OBJS = PolytermsP.o computepoly.o

all: $(OBJS)
	$(CC) $(FLAGS) bin/*.o -o bin/compute-poly
	
PolytermsP.o: PolytermsP.cpp
	$(CC) $(FLAGS) -c PolytermsP.cpp -o bin/$@
	
computepoly.o: computepoly.cpp
	$(CC) $(FLAGS) -c computepoly.cpp -o bin/$@

.PHONY: clean
clean:
	rm -f bin/compute-poly
	rm -f bin/*.o
