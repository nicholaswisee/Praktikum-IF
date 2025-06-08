#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

void separateOddEven(List *l) {
    List evenList, oddList;
	CreateList(&evenList);
	CreateList(&oddList);
	Node* current = *l;
	Node* prev = NULL;

	while (current != NULL) {
		if (current->info % 2 == 1) {
			insertLast(&oddList, current->info);
		} else {
			insertLast(&evenList, current->info);
		}

		current = current->next;
	}
	*l = concat(oddList, evenList);
}