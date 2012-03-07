#include "LList.h"

/**
 * LList constructor
 * Initializes head, tail, and size values
 */
LList::LList() {
	head = NULL;
	tail = NULL;
	size = 0;
}

/**
 * LList deconstructor
 * Delete's all nodes in the list from memory
 */
LList::~LList() {
	if(head != NULL) {
		// Run through all elements in the LList starting at the head and delete from memory
		Node_t* cur = NULL;
		Node_t* next = head->next;
		while(next != NULL) {
			cur = next;
			next = cur->next;
			delete cur;
		}
		delete head;
	}
	head = NULL;
	tail = NULL;
}

/**
 * Push
 * Add's a node to the end of the Linked List. (Stack) FILO
 */
void LList::push(Node_t* n) {
	// List is empty
	if(head == NULL) {
		// Set incomming node as the head and tail
		head = n;
		tail = n;
	} else {
		// Append element to current tail
		tail->next = n;
		n->prev = tail;
		n->next = NULL;
		tail = n; // The new tail will then be this node n being inserted
	}
	size++;
}

/**
 * Push Front
 * Add's a node to the front of a Linked List. (Queue) FIFO
 */
void LList::push_front(Node_t* n) {
	// List is empty
	if(head == NULL) {
		// Set incomming node as the head and tail
		head = n;
		tail = n;
	} else {
		// Add element as new head
		head->prev = n;
		n->next = head;
		head = n;
	}
	size++;
}

/**
 * Pop
 * Return's the last element in the Linked List. (Stack) FILO
 */
Node_t* LList::pop() {
	// The list must have at least one element
	if(head == NULL)
		return NULL;

	Node_t* end = tail;

	// If the tail isn't also the head, set the new tail to be the previous element of the current tail
	if(tail != head) {
		tail->prev->next = NULL;
		tail = tail->prev;
	} else {
		head = NULL;
		tail = NULL;
	}
	
	size--;

	return end;
}

/**
 * Pop Front
 * Return's the first element in the Linked List. (Queue) FIFO
 */
Node_t* LList::pop_front() {
	// The list must have at least one element
	if(head == NULL)
		return NULL;

	Node_t* start = head;

	// If the tail isn't also the head, set the new head to the element directly after it
	if(tail != head) {
		head->next->prev = NULL;
		head = head->next;
		// Reached the end and there's only one element, both are head & tail
		if(head->next == NULL)
			tail = head;
	} else {
		head = NULL;
		tail = NULL;
	}
	
	size--;

	return start;
}

/**
 * Insert
 * Insert a Node into the list at a specific position
 */
bool LList::insert(Node_t* n, int position) {
	if(head == NULL && position > 0)
		return false;
	
	// Find the current node at the position to insert the new Node at
	int i = 0;
	Node_t* cur = head;
	while(cur != NULL) {
		if(i == position)
			break;
			
		cur = cur->next;
			
		i++;
	}
	
	// Trying to insert an element at an invalid position, bail
	if(i != position)
		return false;
		
	// Adjust pointers for the current node to insert the new Node n in the list
	n->prev = cur->prev;
	n->next = cur;
	cur->prev->next = n;
	cur->prev = n;

	size++;

	return true;
}

/**
 * Remove
 * Remove a Node at a specific position
 *
 * @return Pointer to node object that was removed
 */
Node_t* LList::remove(int position) {
	if(head == NULL)
		return NULL;
	
	// Find the current node at the position to remove at
	int i = 0;
	Node_t* cur = head;
	while(cur != NULL) { 
		if(i == position)
			break;
			
		cur = cur->next;
		
		i++;
	}
	
	// Trying to remove at an invalid position, bail
	if(i != position)
		return NULL;
		
	// Adjust pointers for surrounding nodes after the removal
	cur->prev->next = cur->next;
	if(cur->next != NULL)
		cur->next->prev = cur->prev;

	size--;
	
	return NULL;
}

/**
 * Contains Value
 * Linearly searched list for a particular value. The FIRST time it's present in ANY node, the function returns true
 *
 * @param val The value to match against the Node's in the list
 * @return True if the value was found in a node
 */
bool LList::containsValue(int val) {
	Node_t* next = head;
	while(next != NULL) {
		if(next->value == val)
			return true;
		next = next->next;
	}
	return false;
}

/**
 * Print
 * Returns a string representation of the list
 *
 * @return String of elements values
 */
string LList::print() {
	stringstream ss;
	Node_t* next = head;
	while(next != NULL) {
		ss << next->value << " ";
		next = next->next;
	}
	return ss.str();
}
