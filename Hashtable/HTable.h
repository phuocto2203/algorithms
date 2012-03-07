#ifndef _htable_h_
#define _htable_h_

#include <string>
#include <sstream>
#include <math.h>

#include "LList.h"

using namespace std;

class HTable {
private:
	int size; // # of slots
	double alpha; // alpha for linear hash key
	LList** slots;

private:
	// Need to calculate modulus of floating point numbers. Built in operator % does not work 
	double mod(double a, double b) {
		int x = (int)( a / b );
		return a - (double)(x) * b;
	}

public:
	HTable(int, double);
	~HTable();

	string print();

	void chainedInsert(int);
	int chainedSearch(int);

	void linearInsert(int);
	string linearSearch(int);

	void doubleInsert(int);
	string doubleSearch(int);

	// Returns the number of slots
	int getSize() {
		return size;
	}
};


#endif
