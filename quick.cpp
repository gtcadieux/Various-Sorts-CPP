// quick.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
	// Begin recursive sort
	l.head = qsort(l.head, numeric);
}

Node *qsort(Node *head, bool numeric) {
	// Basically same as merge sort base case
	if((head == NULL) || (head->next == NULL)) {
		return head;
	}

	// Choose a pivot element, we will choose the first elment, or the head
	Node *pivot = head;
	
	// Create two node pointers that we are going to bring all elements except the pivot
	// to the right or left of the pivot by calling partition, this is much like merge's split
	Node * left = NULL;
	Node * right = NULL;
	partition(head->next, pivot, left, right, numeric);
	
	// Now we recursively sort the lists very similarly to merge sort
	left = qsort(left, numeric);
	right = qsort(right, numeric);

	// Connect the pivot to the right sublist then concatenate the left sublist to the pivot
	pivot->next = right;
	return concatenate(left, pivot);
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
	Node *current = head;
	while (current) {
		// Node pointer place holder for the head pointer to fall back to
		Node *next = current->next;
	
		// If a number (or string) in the head list is less than our pivot, put it in the left sublist
		// Otherwise, put it in the right sublist
		if (numeric) {	
			if (current->number < pivot->number) {
				current->next = left;
				left = current;
			}
			else {
				current->next = right;
				right = current;
			}
		}
		else {
			if (current->string < pivot->string) {
				current->next = left;
				left = current;
			}
			else {
				current->next = right;
				right = current;
			}
		}
		// Bring the head pointer to the next node it must analyze
		current = next;
	}
}

Node *concatenate(Node *left, Node *right) {
	if (left == NULL) {
		return right;
	}
	
	Node *curr = left;
	while (curr->next) {
		curr = curr->next;
		
	}
	curr->next = right;
	return left;
}

