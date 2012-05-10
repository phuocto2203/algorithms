#include "PolytermsP.h"

/**
 * Polynomial Constructor
 * Initializes internal linked list of terms
 */
Polynomial::Polynomial() {
	head = NULL;
	size = 0;
}

/**
 * Polynomial Destructor
 * Cleans up internal terms linked list
 */
Polynomial::~Polynomial() {
	clearTerms();
}

/**
 * Polynomial Copy Constructor
 * Initializes internal linked list of terms and then copies the terms from another polynomial p
 */
Polynomial::Polynomial(Polynomial* p)
{
	head = NULL;
	size = 0;

	// Loop through the passed Polynomial (p) and replicate all terms in this polynomial
	Term* current = p->getHead();
	Term* pt = NULL; // Previous term that was added
	Term* nt = NULL; // New term to be added
	while(current != NULL) {
		// Create a new term to add to this polynomial
		nt = new Term(current->coeff, current->exp);

		// Fix previous and next pointers in the new term
		nt->prev = pt;
		if (pt != NULL)
			pt->next = nt;

		// If this is the first term being added, it's the head of this Polynomial
		if(size == 0)
			head = nt;

		size++;
		current = current->next; // Get the next term to be added
		pt = nt; // The term that was just added becomes the previous term
	}
}

/**
 * Clear Terms
 * Removes and deletes all terms from memory
 */
void Polynomial::clearTerms() {
	// Delete all Terms from memory
	if(head != NULL) {
		Term* current = NULL;
		Term* n = head->next;
		while(n != NULL) {
			current = n;
			n = current->next;
			delete current;
			current = NULL;
		}
		delete head;
		head = NULL;
	}
	size = 0;
}

/**
 * Add Term
 * Adds a term to the Polynomial with a given coefficient and exponent
 * Like terms will be simplified, exponents must be non-zero
 */
void Polynomial::addTerm(coeff_t c, int e)
{
	if(e < 0) {
		cerr << "Exponents must be positive." << endl;
		return;
	}
	
	if (head == NULL) { // List is empty, new term becomes the head of this polynomial
		head = new Term(c, e);
		size++;
	} else {
		// Find the the point in the linkedlist to add the new Term - this might be the end, or in the middle, of the linkedlist.
		// This will combine Terms with like powers and order terms by descending exponenets (which will help with division)
		Term* cur = head;
		Term* prev = NULL;
		Term* n = NULL;
		while(cur != NULL) {
			// If the current Term has the same exponent as the Term we're trying to add, combine the coefficients
			// and return from the function early
			if(cur->exp == e) {
				cur->coeff += c;

				// If the coefficient becomes 0, remove the Term from the polynomial by unlinking the Term node and deleting it from memory
				if(cur->coeff == 0) {
					if(prev != NULL)
						prev->next = cur->next;
					else
						head = cur->next; // If the cur Term has no prev element, then it is the head of the list. The new head becomes cur->next
					if(cur->next != NULL)
						cur->next->prev = prev;
					delete cur;
					size--;
				}

				return;
			} else if(cur->exp < e) { // If the exponent of the next term is less than the term to be added, break here
				break;
			}

			// Move to the next Term & track the previous Term
			prev = cur;
			cur = cur->next;
		}

		// The point of insertion in the linkedlist has been reached, add the Term here and fix pointers
		n = new Term(c, e);
		if(prev != NULL) {
			n->prev = prev;
			prev->next = n;
		} else {
			head = n;
		}
		if(cur != NULL) {
			n->next = cur;
			cur->prev = n;
		}
		size++;
	}
}

/**
 * Add Poly
 * Adds two polynomials together and stores the result in the current Polynomial object
 * Both polynomials must be non-empty
 * Returns true upon success, false if otherwise
 */
bool Polynomial::addPoly(Polynomial* poly1, Polynomial* poly2)
{
	if (poly1->getHead() == NULL || poly2->getHead() == NULL) {
		cerr << "Polynomial 1 or 2 doesn't have any terms" << endl;
		return false;
	}

	// Loop through the first polynomial and add it to the current Polynomial ('sum')
	for (Term* cur = poly1->getHead(); cur != NULL; cur = cur->next)
		this->addTerm(cur->coeff, cur->exp);

	// Loop through the second polynomial and add it to the current Polynomial ('sum')
	// Any terms that have a matching exponent already in 'sum' will be combined in the 'addTerm' function
	for (Term* cur = poly2->getHead(); cur != NULL; cur = cur->next)
		this->addTerm(cur->coeff, cur->exp);

	return true;
}

/**
 * Sub Poly
 * Subtracts poly1 from poly2 and stores the result in the current Polynomial object
 * Both polynomials must be non-empty
 * Returns true upon success, false if otherwise
 */
bool Polynomial::subPoly(Polynomial* poly1, Polynomial* poly2)
{
	if (poly1->getHead() == NULL || poly2->getHead() == NULL) {
		cerr << "Polynomial 1 or 2 doesn't have any terms" << endl;
		return false;
	}

	// Loop through the first polynomial and store it to the current Polynomial (called 'diff')
	for (Term* cur = poly1->getHead(); cur != NULL; cur = cur->next)
		this->addTerm(cur->coeff, cur->exp);

	// Loop through the second polynomial and store it to the current Polynomial (called 'diff')
	// Any terms that have a matching exponent already in 'diff' will be combined in the 'subTerm' function
	for (Term* cur = poly2->getHead(); cur != NULL; cur = cur->next)
		this->addTerm(cur->coeff*-1, cur->exp); // Multiply coefficients by -1 to perform a subtraction from the first batch of terms in poly1

	return true;
}

/**
 * Mult Poly
 * Multiplies two polynomials together and stores the result in the current Polynomial object
 * Returns true upon success, false if otherwise
 */
bool Polynomial::multPoly(Polynomial* poly1, Polynomial* poly2)
{
	// Loop through each term in polynomial 1 and multiply it by each term in polynomial 2
	for (Term* cur1 = poly1->getHead(); cur1 != NULL; cur1 = cur1->next)
	{
		for (Term* cur2 = poly2->getHead(); cur2 != NULL; cur2 = cur2->next)
		{
			// Add the result to the resulting polynomial: 'product'
			this->addTerm(cur1->coeff * cur2->coeff, cur1->exp + cur2->exp);
		}
	}

	return true;
}

/**
 * Div Term
 * Divides the numerator into the denominator
 * The denominator must be Non-zero
 * Returns the resulting Term, NULL if there was an error (divide by zero)
 */
Term* Polynomial::divTerm(Term* numerator, Term* denominator) {
	if(denominator->coeff == 0)
		return NULL;
	Term* res = new Term();
	res->exp = numerator->exp - denominator->exp;
	res->coeff = numerator->coeff / denominator->coeff;
	return res;
}

/**
 * Div Poly
 * Divides poly1 into poly2 and stores the result in the current Polynomial object
 * The remainder will be stored in the Polynomial parameter passed as 'remainder'
 * poly1 and poly2 must be non-empty
 * Returns true upon success, false if otherwise
 */
bool Polynomial::divPoly(Polynomial* poly1, Polynomial* poly2, Polynomial* remainder)
{
	if(remainder == NULL) {
		cerr << "The remainder polynomial is null" << endl;
		return false;
	}
	
	if (poly1->getHead() == NULL || poly2->getHead() == NULL) {
		cerr << "Polynomial 1 or 2 doesn't have any terms" << endl;
		return false;
	}

	Polynomial* numerator = new Polynomial(poly1);
	Term* t1 = numerator->getHead(); // Highest term in the running numerator
	Term* t2 = poly2->getHead();

	while(t1 != NULL && (t1->exp >= t2->exp)) {
		// Divide the highest term in the running numerator (t1) by the highest term in the divisor (t2)
		Term* t3 = divTerm(t1, t2);
		if(t3 == NULL)
			break;

		// This result is then added to the quotient
		//cout << "adding t3: c=" << t3->coeff << ". e=" << t3->exp << endl;
		this->addTerm(t3->coeff, t3->exp);
		//cout << "quotient: " << this->prettyPrint() << endl;

		// Multiply the entire denominator (poly2) by the quotient
		Polynomial* temp = new Polynomial();
		Polynomial* multiplier = new Polynomial();
		multiplier->addTerm(t3->coeff, t3->exp);
		//cout << poly2->prettyPrint() << " X " << multiplier->prettyPrint() << endl;
		temp->multPoly(poly2, multiplier);

		// Subtract temp from the running numerator. The result is our new numerator
		Polynomial* oldNumer = new Polynomial(numerator);
		//cout << "oldNumer: " << oldNumer->prettyPrint() << endl;
		//cout << "subtractant: " << temp->prettyPrint() << endl;
		numerator->clearTerms();
		numerator->subPoly(oldNumer, temp);
		
		//cout << "new numer: "<< numerator->prettyPrint() << endl;
		delete oldNumer;
		delete temp;
		delete multiplier;
		delete t3;

		// Grab the next leading term (if any)
		t1 = numerator->getHead();
	}

	// Accumulate remainer
	Term* r = t1;
	while(r != NULL) {
		remainder->addTerm(r->coeff, r->exp);
		r = r->next;
	}

	delete numerator;

	return true;
}

/**
 * Print
 * Print the polynomial as per program specs
 */
string Polynomial::print() {
	if(size == 0)
		return "0 0";

	stringstream p;

	Term* cur = head;
	while(cur != NULL) {
		p << cur->coeff << " " << cur->exp << "\n";
		cur = cur->next;
	}

	return p.str();
}

/**
 * Pretty Print
 * Print the polynomial in human readable form
 */
string Polynomial::prettyPrint() {
	if(size == 0)
		return "0";

	stringstream p;

	Term* cur = head;
	while(cur != NULL) {
		p << cur->coeff << "x^" << cur->exp;
		if(cur->next != NULL)
			p << " + ";
		cur = cur->next;
	}

	return p.str();
}
