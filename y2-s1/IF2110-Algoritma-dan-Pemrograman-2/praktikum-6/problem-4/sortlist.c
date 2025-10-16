#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Fungsi yang melakukan pengurutan dengan urutan menaik jika asc = true
 * dan menurun jika asc = false
 * 
 * I.S. List l terdefinisi dan berisi setidaknya 1 elemen
 * F.S. List l terurut secara urutan tertentu
 * 
 * Contoh: 
 * - Untuk l = [1, 5, 2, 3, 3], maka setelah sort(&l, true), l menjadi [1, 2, 3, 3, 5]
 */

void sort(List *l, boolean asc) {
	if (isEmpty(*l) || (*l)->next == NULL) {
		return; 
	}

	Node* p;
	Node* q;
	boolean swapped;

	// Izin bubble-sort ketua

	do {
		swapped = false;
		p = *l;


		while (p->next != NULL) {
			q = p->next;
			if ((asc && (p->info > q->info)) || (!asc && (p->info < q->info))) {
				ElType temp = p->info;
				p->info = q->info;
				q->info = temp;
				swapped = true;

			}

			p = p->next;
		}

	} while (swapped);
}