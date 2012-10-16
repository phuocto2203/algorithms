#include <iostream>

#include "Sorting.h"

#define ARR_LEN 10

using namespace std;

int main() {
	Sorting algs;
	
	// Initalize arrays to be sorted with ARR_LEN random integers between 0 and ARR_LEN0
	int *qtest = new int[ARR_LEN];
	int *mtest = new int[ARR_LEN];
	int *itest = new int[ARR_LEN];
	int *irtest = new int[ARR_LEN];
	int *stest = new int[ARR_LEN];
	algs.initRandArray(qtest, ARR_LEN, 0, 100);
	algs.initRandArray(mtest, ARR_LEN, 0, 100);
	algs.initRandArray(itest, ARR_LEN, 0, 100);
	algs.initRandArray(irtest, ARR_LEN, 0, 100);
	algs.initRandArray(stest, ARR_LEN, 0, 100);
	
	cout << "Sorting Algorithms" << endl;
	
	
	// Quick Sort
	cout << "Quick: ";
	algs.printArray(qtest, ARR_LEN);
	algs.quickSort(qtest, 0, ARR_LEN);
	cout << "Result: ";
	algs.printArray(qtest, ARR_LEN);
	cout << endl;
	
	// Merge Sort
	cout << "Merge: ";
	algs.printArray(mtest, ARR_LEN);
	algs.mergeSort(mtest, 0, ARR_LEN);
	cout << "Result: ";
	algs.printArray(mtest, ARR_LEN);
	cout << endl;
	
	// Insertion Sort
	cout << "Insertion: ";
	algs.printArray(itest, ARR_LEN);
	algs.insertionSort(itest, ARR_LEN);
	cout << "Result: ";
	algs.printArray(itest, ARR_LEN);
	cout << endl;
	
	// Insertion Sort Recursive
	cout << "Insertion, Recursive: ";
	algs.printArray(irtest, ARR_LEN);
	algs.recursiveInsertionSort(irtest, ARR_LEN);
	cout << "Result: ";
	algs.printArray(irtest, ARR_LEN);
	cout << endl;
	
	// Selection Sort
	cout << "Selection: ";
	algs.printArray(stest, ARR_LEN);
	algs.selectionSort(stest, ARR_LEN);
	cout << "Result: ";
	algs.printArray(stest, ARR_LEN);
	cout << endl;
	
	delete qtest;
	delete mtest;
	delete itest;
	delete irtest;
	delete stest;
	
	return 0;
}

