#ifndef _llist_h_
#define _llist_h_

#include <string>
#include <sstream>
using namespace std;

#ifndef NULL
#define NULL 0
#endif

typedef struct Node {
	Node(int val) : prev(NULL), next(NULL), value(0) { value = val; }
	struct Node* prev;
	struct Node* next;
	int value;
} Node_t;

class LList {
private:
	int size;
	Node_t *head, *tail;

public:
	LList();
	~LList();

	void push(Node_t* n);
	void push_front(Node_t* n);
	Node_t* pop();
	Node_t* pop_front();

	bool insert(Node_t* n, int position);
	Node_t* remove(int position);

	bool containsValue(int value);

	string print();

	int getSize() {
		return size;
	}
};
#endif
