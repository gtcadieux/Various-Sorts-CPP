// qsort.cpp

#include "volsort.h"
#include <stdlib.h>
#include <algorithm>
#include <iostream>


void qsort_sort(List &l, bool numeric) {
	int size = l.size;
	Node* arr[size];
	int count = 0;
	// Load list elements into an array, either the string or number
	// I may have been able to just load number and string into the array no matter what
	// but this method felt a little safer
	for(Node * curr = l.head; curr != NULL; curr = curr->next) {
		if (numeric) {					
			arr[count] = new Node;			
			arr[count]->number = curr->number;
		}
		else {
			
			arr[count] = new Node;
			arr[count]->string = curr->string;
		}
		count++;
	}
	count = 0;

	if (numeric) { // qsort takes array, size of array, sizeof the array type (Node*), uses function to compare
		qsort(arr, size, sizeof(Node*), c_node_num_compare);
	}

	else {
		qsort(arr, size, sizeof(Node*), c_node_string_compare);
	}

	l.head = arr[0];	//Set head node to arr[0]
	Node * curr = l.head;	// use new pointer to set all next pointers in the correct order
	for(int i = 0; i < size; i++) {
		if (i == (size - 1)) {	// if last element in arr, make next point to NULL
			curr->next = NULL;
		}
		else {
			curr->next = arr[i + 1];
		}
		curr = curr->next;
	}
	

return;

}

