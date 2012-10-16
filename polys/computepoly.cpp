#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "PolytermsP.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3) {
		cerr << "Command requires <input_file> <output_file>" << endl;
		return 0;
	}

	// Open files
	ifstream iFile;
	ofstream oFile;
	iFile.open(argv[1]);
	oFile.open(argv[2]);
	if ( !iFile.is_open() || !oFile.is_open() ) {
		cerr << "Failed to open the input or output files" << endl;
		return -1;
	}

	// Input polynomials from file
	Polynomial* poly1 = new Polynomial();
	Polynomial* poly2 = new Polynomial();
	Polynomial* ipoly = poly1; // Pointer to the polynomial currently recieving input

	// Results stored in these polynomials
	Polynomial* addRes = new Polynomial();
	Polynomial* multRes = new Polynomial();
	Polynomial* divRes = new Polynomial();
	Polynomial* remRes = new Polynomial();

	// Read input file line by line
	bool xin = false;
	coeff_t c = 0;
	int e = 0;
	string line = "";
	while(!iFile.eof()) {
		// Get the current line and put it into a stringstream for parsing
		line.erase();
		getline(iFile, line);
		stringstream sline(line);

		// Switch the input polynomial to poly2
		if(line.find("X") != string::npos) {
			xin = true;
			ipoly = poly2;
			continue;
		}

		// Parse the coefficient and exponent from the same line and add it to the current input polynomial
		sline >> c >> e;
		ipoly->addTerm(c, e);
	}

	if(!xin) {
		cerr << "Error: Two polynomials were not present in the input file (absence of XXX string)" << endl;
		goto end;
	}

	cout << "Polynomial 1: " << poly1->prettyPrint() << endl;
	cout << poly1->print() << endl;
	cout << "Polynomial 2: " << poly2->prettyPrint() << endl;
	cout << poly2->print() << endl;

	// Perform operations
	if(!addRes->addPoly(poly1, poly2)) {
		cerr << "Error: Addition of polynomials failed" << endl;
	}
	if(!multRes->multPoly(poly1, poly2)) {
		cerr << "Error: Multiplication of polynomials failed" << endl;
	}
	if(!divRes->divPoly(poly1, poly2, remRes)) {
		cerr << "Error: Division of polynomials failed" << endl;
	}

	cout << "Addition: " << addRes->prettyPrint() << endl;
	cout << addRes->print() << endl;
	oFile << addRes->print();
	oFile << "YYY" << endl;

	cout << "Muliplication: " << multRes->prettyPrint() << endl;
	cout << multRes->print() << endl;
	oFile << multRes->print();
	oFile << "ZZZ" << endl;

	cout << "Division: " << divRes->prettyPrint() << endl;
	cout << divRes->print() << endl;
	oFile << divRes->print();
	oFile << "RRR" << endl;

	cout << "Divison Remainder: " << remRes->prettyPrint() << endl;
	cout << remRes->print() << endl;
	oFile << remRes->print() << endl;

	end:

	// Close files
	iFile.close();
	oFile.close();

	// Delete polynomials from memory
	delete poly1;
	delete poly2;
	delete addRes;
	delete multRes;
	delete divRes;
	delete remRes;

	return 0;
}
