// merge.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

void merge_sort(List &l, bool numeric) {
	l.head = msort(l.head, numeric);
}

Node *msort(Node *head, bool numeric) {
	if ((head == NULL) || (head->next == NULL)) {
		// If there is only 1 node, or no node at all, return head
		return head;
	}
	// Create a left and right node so we can call split
	Node * left;
	Node * right;
	// Split the list into left and right
	split(head, left, right);
	// Call msort on the left and right sides to recursively sort the list
	left = msort(left, numeric);
	right = msort(right, numeric);
	// Once left and right are sorted, we need to merge them
	return merge(left, right, numeric);
}

void split(Node *head, Node *&left, Node *&right) {
	if ((head == NULL) || (head->next == NULL)) {
		left = head;
		right = NULL;
	}
	else {
		Node * slow = head;
		Node * fast = head->next;
		// While fast is not pointing to NULL, nor is its next pointer pointing to NULL
		// tick slow down the list 1, and tick fast down the list 2
		while((fast != NULL) && (fast->next != NULL)) { 
			slow = slow->next;
			fast = fast->next->next;
		}
		left = head;	// Set left to the head of the list, and right to the middle of the list
		right = slow->next;
		slow->next = NULL;	// Disconnect the two lists
	}
}

Node *merge(Node *left, Node *right, bool numeric) {

	Node *tempNode = new Node();
	Node *build = tempNode;

	while((left != NULL) && (right != NULL)) { // If one of the lists are empty, append the rest
		if (numeric) {
			if (left->number <= right->number) { // If left list's current number is less than right's
				build->next = left;				// append and move left's pointer to the next element
				left = left->next;
			}
			else {
				build->next = right;
				right = right->next;
			}
		}
		else {
			if (left->string <= right->string) {	// Same logic as previous, just compare strings
				build->next = left;
				left = left->next;
			}
			else {
				build->next = right;
				right = right->next;
			}
		}
		build = build->next;	// Progress build to prepare appending another node
	}

	if (left != NULL) {	// if left is not empty, append what is remaining to build
		build->next = left;
	}
	else {				// otherwise append from the right list
		build->next = right;
	}

	Node *head = tempNode->next;
	delete tempNode;
	return head;
}

