/**
 * Ramsey Kant, CSE310: T Th 1:30 - 2:45
 * 3/1/12
 * Hashtable Program, Assignment 4
 */

#include <iostream>
#include <fstream>
#include <string>

#include "HTable.h"

using namespace std;

int main(int argv, char** argc) {
	if(argv != 2) {
		cout << "Incorrect number of arguments!\n";
		cout << "Usage: hashtable path/to/input.txt\n";
		return -1;
	}

	string filename = argc[1];
	// p = size of HT (slots)
	// n = number of keys to read & inserted
	// s = key to search for after all elements are inserted
	int p = 0, n = 0, s = 0;
	double alpha = 0.0; // used in linear hashing, pass to the HT
	HTable *cHT, *lHT, *dHT; // Chained, Linear, and Double hash tables
	int* keys; // Array of size n with input keys read from the file

	// Read the input file for all necessary variables & keys
	cout << "Reading input file " << filename.c_str() << endl;
	
	ifstream fin;
	fin.open(filename.c_str(), ios::in);
	if(!fin.is_open()) {
		cout << "Problem opening the file\n";
		fin.close();
		return -1;
	}

	fin >> p;
	fin >> alpha;
	fin >> n;

	// Loop through the same number of lines that contain a key and drop it into the keys array
	keys = new int[n];
	for(int i = 0; i < n; i++) {
		fin >> keys[i];
	}

	// Grab the key to search for (the last line)
	fin >> s;

	fin.close();

	// Print values read from the input file
	cout << "p = " << p << ", alpha = " << alpha << ", n = " << n << ", s = " << s << endl;
	cout << "Keys[" << n << "]" << endl;
	for(int i = 0; i < n; i++)
		cout << keys[i] << " ";
	cout << endl;

	// Create Hashtables
	cHT = new HTable(p, alpha);
	lHT = new HTable(p, alpha);
	dHT = new HTable(p, alpha);
	ofstream fo;
	string output;

	///
	// Chained HT tests

	cout << "Chained HT tests: (chained-output.txt)" << endl;
	fo.open("chained-output.txt", ios::out | ios::trunc);
	if(!fo.is_open()) {
		cout << "Could not open chained-output.txt for writing\n";
		return -1;
	}

	// Insert keys
	for(int i = 0; i < n; i++)
		cHT->chainedInsert(keys[i]);
	output = cHT->print();
	cout << cHT->print();
	fo << output;

	// Search for element s
	int found = cHT->chainedSearch(s);
	cout << found << endl;
	fo << found << endl;

	fo.close();

	///
	// Linear HT tests

	cout << "\nLinear HT tests (linear-output.txt):" << endl;
	fo.open("linear-output.txt", ios::out | ios::trunc);
	if(!fo.is_open()) {
		cout << "Could not open linear-output.txt for writing\n";
		return -1;
	}

	// Insert keys
	for(int i = 0; i < n; i++)
		lHT->linearInsert(keys[i]);
	output = lHT->print();
	cout << output;
	fo << output;

	// Search
	output = lHT->linearSearch(s);
	cout << output << endl;
	fo << output << endl;

	fo.close();

	///
	// Double HT tests

	cout << "\nDouble HT tests: (double-output.txt)" << endl;
	fo.open("double-output.txt", ios::out | ios::trunc);
	if(!fo.is_open()) {
		cout << "Could not open double-output.txt for writing\n";
		return -1;
	}

	// Insert keys
	for(int i = 0; i < n; i++)
		dHT->doubleInsert(keys[i]);
	output = dHT->print();
	cout << output;
	fo << output;

	// Search
	output = dHT->doubleSearch(s);
	cout << output << endl;
	fo << output << endl;

	fo.close();

	delete cHT;
	delete lHT;
	delete dHT;
	delete [] keys;

	return 0;
}
