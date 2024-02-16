#include "volsort.h"
#include <stdexcept>
using namespace std;

List::List() {
	head = NULL;
	size = 0;
}

List::~List() {

			Node *p = head;
			while (p != NULL) {
				Node *next = p->next;
				delete p;
				p = next;
			}
			head = NULL;	
}

void List::push_front(const string &s) {
	Node *p = new Node;
	p->string = s;
	try {	// This prevents stoi from throwing errors when it tries to convert some strings
		p->number = stoi(s);
	} catch (const invalid_argument&) {
		p->number = 0;
	} catch (const out_of_range&) {
		p->number = 0;
	}
	p->next = head;
	head = p;
	
}
bool node_number_compare(const Node *a, const Node *b) {
	return a->number < b->number;
}
bool node_string_compare(const Node *a, const Node *b) {
	return a->string < b->string;
}
int c_node_string_compare(const void *a, const void * b) {
	Node* n1 = *(Node**)a;
	Node* n2 = *(Node**)b;
	return n1->string.compare(n2->string);
}
int c_node_num_compare(const void * a, const void * b) { //C++ qsort reference
	Node* n1 = *(Node**)a;
	Node* n2 = *(Node**)b;
	return n1->number - n2->number;
}

