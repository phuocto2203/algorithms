#ifndef _POLYTERMSP_H_
#define _POLYTERMSP_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

typedef int coeff_t; // User allowed to modify coeff type

// Represents a term in the Polynomial
typedef struct Term_T {
	coeff_t coeff;
	int exp; // Positive integers inc. zero only.

	struct Term_T* next;
	struct Term_T* prev;

	Term_T (coeff_t c = 1, int e = 0) { 
		coeff = c;
		exp = e;
		next = NULL;
		prev = NULL;
	}
} Term;

class Polynomial
{
private:
	Term* head;
	int size;

public:
	Polynomial();
	~Polynomial();
	Polynomial(Polynomial* p);

	// Operators
	void clearTerms();
	void addTerm(coeff_t c, int e);
	bool addPoly(Polynomial* poly1, Polynomial* poly2);
	bool subPoly(Polynomial* poly1, Polynomial* poly2);
	bool multPoly(Polynomial* poly1, Polynomial* poly2);
	Term* divTerm(Term* numerator, Term* denominator);
	bool divPoly(Polynomial* poly1, Polynomial* poly2, Polynomial* remainder);

	// Getters
	Term* getHead() {
		return head;
	}

	int getSize() {
		return size;
	}

	// Printers
	string print(); // Output expected for the assignments output files
	string prettyPrint(); // Nice output with variable x
};

#endif
