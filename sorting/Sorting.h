#ifndef _SORTING_H_
#define _SORTING_H_

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

class Sorting {
private:
	
public:
	Sorting();
	~Sorting();

	// Quick
	// Worst: O(n^2) Best: O(nlogn) Average: O(nlogn)
	int qpartition(int* arr, int start, int end, int pivot);
	void quickSort(int* arr, int start, int end);

	// Merge
	// Worst: O(nlogn) Best: O(nlogn) Average: O(nlogn)
	void mergeSort(int* arr, int low, int high);
	void merge(int* arr, int low, int high);
	
	// Insertion
	// Worst: O(n^2) Best: O(n) Average: O(n^2)
	void insertionSort(int* arr, int len);
	void recursiveInsertionSort(int* arr, int len);
	void recursiveInsert(int* arr, int len);
	
	// Selection
	// Worst: O(n^2)
	void selectionSort(int* arr, int len);
	
	// Utility
	void swap(int* arr, int a, int b);
	void initRandArray(int* arr, int len, int low, int high);
	void printArray(int* arr, int len);
};

#endif
