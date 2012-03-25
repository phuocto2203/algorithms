# Makefile for red black tree program

CC = g++
# -g flag is for gdb info
FLAGS = -g -Wall
OBJS = RBTree.o main.o

all: $(OBJS)
	$(CC) $(FLAGS) bin/*.o -o bin/rbtree

RBTree.o: RBTree.cpp
	$(CC) $(FLAGS) -c RBTree.cpp -o bin/$@

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp -o bin/$@

clean:
	rm -f *.gch bin/* *~ \#*