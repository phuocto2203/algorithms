#ifndef _SORTING_H_
#define _SORTING_H_

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Sorting {
private:
	
public:
	Sorting();
	~Sorting();

	// Quick
	// Worst: O(n^2) Best: O(nlogn) Average: O(nlogn)
	int qpartition(char* arr, int start, int end, int pivot);
	void quickSort(char* arr, int start, int end);

	// Merge
	void mergesort(int* arr, int low, int high);
	void merge(int* arr, int low, int high);
	
	// Insertion
	// Worst: O(n^2) Best: O(n) Average: O(n^2)
	void insertionSort(char* arr, int len);
	void recursiveInsertionSort(char* arr, int len);
	void recursiveInsert(char* arr, int len);
	
	// Utility
	void initRandArray(char* arr, int len, int low, int high);
	void printArray(char* arr, int len);
};

#endif