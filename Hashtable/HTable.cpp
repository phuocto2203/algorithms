#include "HTable.h"

/**
 * Hashtable Constructor
 * Initializes and instantiates slots array and each Linked List within a slot
 */
HTable::HTable(int s, double a) {
	alpha = a;
	size = s;

	slots = new LList *[size];

	// Initialize all slots in the vector as linked lists
	for(int i = 0; i < size; i++) {
		slots[i] = new LList();
	}
}

/**
 * Hashtable Deconstructor
 * Free's memory allocated on the heap during the lifetime of the application
 */
HTable::~HTable() {
	// Delete any linked lists in the slots vector that are still on the heap
	if(slots != NULL) {
		for(int i = 0; i < size; i++) {
			if(slots[i] != NULL)
				delete slots[i];
		}
		delete slots;
	}
	slots = NULL;
}

/**
 * Print
 * Return a string representation of each slot and the contents of their linked lists
 *
 * @return String representation of all slots
 */
string HTable::print() {
	stringstream ss;
	for(int i = 0; i < size; i++) {
		ss << i << ": " << slots[i]->print() << "\n";
	}
	return ss.str();
}

///
// Chained HT

/**
 * Chained Key Insert
 * Inserts a key into a linked list at the appropriate chained hash table slot
 * Hash of a key conforms to k mod p (where p is the number of slots in the HT)
 *
 * @param key The key to insert into the table
 */
void HTable::chainedInsert(int key) {
	// Calculate the slot where the key should reside
	int hash = key%size;

	// Push to the front of the linked list, making the most recent element at the head
	slots[hash]->push_front(new Node_t(key));
}

/**
 * Chained Key Search
 * Searches for a key in a chained hash table and returns the slot it was found in
 *
 * @param key The key to search for
 * @return The slot the key was found in. -1 if not found
 */
int HTable::chainedSearch(int key) {
	// Calculate the hash where the key should be present
	int hash = key%size;

	// Check to see if it's actually there in the linked list at the index hash (linear search through LList)
	if(slots[hash]->containsValue(key))
		return hash;

	return -1;
}

///
// Linear HT

/**
 * Linear Key Insert (Open addressing)
 * Inserts a key into a linked list at the appropriate linear hash table slot
 * Hash of a key conforms to floor(p((alpha*k) mod 1)+i mod p
 * Note: Linear HT's use open addressing. When all slots are filled, an insertion will NOT be completed
 *
 * @param key The key to insert into the table
 */
void HTable::linearInsert(int key) {
	// Probe until a suitable slot for the particular key is found
	int hash = 0;
	for(int i = 0; i < size; i++) {
		hash = (int)mod((floor(size*(mod((alpha*key), 1)))+i), size);
		// Slot is empty, make the insertion
		if(slots[hash]->getSize() == 0) {
			slots[hash]->push(new Node_t(key));
			return;
		}
	}
}

/**
 * Linear Key Search
 * Searches for a key in a linear hash table and returns a string of probes made to find the key
 *
 * @param key The key to search for
 * @return A string representation of the sequence of probes (slots) made to find the key
 */
string HTable::linearSearch(int key) {
	stringstream ss;
	// Probe until a suitable slot for the particular key is found
	int hash = 0;
	for(int i = 0; i < size; i++) {
		hash = (int)mod((floor(size*(mod((alpha*key), 1)))+i), size);
		ss << hash << " "; // Add the probe to the sequence of slots tested
		// Slot contains the value, then we've found the correct slot. Probing can terminate here
		if(slots[hash]->containsValue(key))
			break;
	}
	return ss.str();
}

///
// Double HT


/**
 * Double Key Insert (Open addressing)
 * Inserts a key into a linked list at the appropriate linear hash table slot.
 * When all slots are filled, an insertion will NOT be made
 * Hash of a key conforms to:
 *	h1 = k mod p
 *	h2 = 1 + (k mod (p-2))
 *	h = h1 + i*h2
 *
 * @param key The key to insert into the table
 */
void HTable::doubleInsert(int key) {
	// Probe until a suitable slot for the particular key is found
	int hash = 0;
	for(int i = 0; i < size; i++) {
		hash = ((key%size) + i*(1+(key%(size-2))))%size;
		// Slot is empty, make the insertion
		if(slots[hash]->getSize() == 0) {
			slots[hash]->push(new Node_t(key));
			return;
		}
	}
}

/**
 * Double Key Search
 * Searches for a key in a double hash table and returns a string of probes made to find the key
 *
 * @param key The key to search for
 * @return A string representation of the sequence of probes (slots) made to find the key
 */
string HTable::doubleSearch(int key) {
	stringstream ss;
	// Probe until a suitable slot for the particular key is found
	int hash = 0;
	for(int i = 0; i < size; i++) {
		hash = ((key%size) + i*(1+(key%(size-2))))%size;
		ss << hash << " "; // Add the probe to the sequence of slots tested
		// Slot contains the value, then we've found the correct slot. Probing can terminate here
		if(slots[hash]->containsValue(key))
			break;
	}
	return ss.str();
}
