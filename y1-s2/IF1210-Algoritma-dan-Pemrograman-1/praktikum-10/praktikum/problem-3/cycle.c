#include "cycle.h"
#include "listlinier.h"
#include "Boolean.h"
#include <stdlib.h>

/**
 * I.S. List l terdefinisi
 * F.S. Mengembalikan address node yang merupakan entrypoint dari cycle
 * Jika tidak ada cycle, kembalikan NULL
 */
Address findCycleEntryPoint(List l){
	if (l == NULL) return NULL;

	// Ide: Kalo emang ada loop, yang slow pasti akan ketemu fast di suatu saat.
	Node* slow = l;
	Node* fast = l;

	// Slow moves through 1 at a time, fast moves through 2 nodes heehhehe
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			break;
		}
	}

	// Misal gak ada nih 
	if (fast == NULL || fast->next == NULL) {
		return NULL;
	}

	// 
	Node* loop = l;
	while (loop != slow) {
		loop = loop->next;
		slow = slow->next;
	}

	return loop;
}
