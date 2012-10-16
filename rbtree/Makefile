# Makefile for red black tree program

CC = g++
FLAGS = -g -O0 -Wall
OBJS = RBTree.o main.o

all: $(OBJS)
	$(CC) $(FLAGS) bin/*.o -o bin/rbtree

RBTree.o: RBTree.cpp
	$(CC) $(FLAGS) -c RBTree.cpp -o bin/$@

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp -o bin/$@

.PHONY: clean
clean:
	rm -f bin/sorting
	rm -f bin/*.o
