# Makefile for hashtable program

CC = g++
FLAGS = -g -O0 -Wall
OBJS = LList.o HTable.o main.o

all: $(OBJS)
	$(CC) $(FLAGS) bin/*.o -o bin/hashtable
	
HTable.o: HTable.cpp
	$(CC) $(FLAGS) -c HTable.cpp -o bin/$@

LList.o: LList.cpp
	$(CC) $(FLAGS) -c LList.cpp -o bin/$@
	
main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp -o bin/$@

.PHONY: clean
clean:
	rm -f bin/sorting
	rm -f bin/*.o
