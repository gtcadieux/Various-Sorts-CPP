// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <iostream>


void stl_sort(List &l, bool numeric) {
	int size = l.size;
	Node* arr[size];
	int count = 0;
	// Loads list elements into array, either the number or string
	// I probably could have just done both at the same time, but this
	// method feels a bit safer
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

	if (numeric) {	// Either sort based on number or string
		std::sort(arr, arr + size, node_number_compare);
	}

	else {
		std::sort(arr, arr + size, node_string_compare);
	}

	l.head = arr[0];		// Set the head of the list to arr[0]
	Node * curr = l.head;
	// Load array elements back into list by updating our next pointers
	for(int i = 0; i < size; i++) {	
		if (i == (size - 1)) {	// If on last element of array, set next to NULL
			curr->next = NULL;
		}
		else {
			curr->next = arr[i + 1];
		}
		curr = curr->next;
	}
	

return;

}

