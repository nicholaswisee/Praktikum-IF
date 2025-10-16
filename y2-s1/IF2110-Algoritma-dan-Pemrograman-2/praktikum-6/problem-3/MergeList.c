#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Fungsi untuk menggabungkan nilai-nilai di antara dua node bernilai 0
 * menjadi satu node dengan nilai hasil penjumlahan, dan menghapus seluruh node 0.
 *
 * I.S.  l terdefinisi, berisi minimal tiga elemen, dengan ketentuan:
 *      - Elemen pertama dan terakhir bernilai 0
 *      - Tidak ada dua node 0 yang bersebelahan
 *
 * F.S.  Setiap rentang elemen di antara dua 0 dijumlahkan menjadi satu node baru,
 *       dan list hasil tidak mengandung nilai 0 sama sekali.
 *
 * Contoh:
 * Jika l = [0,3,1,0,4,5,2,0], maka setelah mergeList(&l), l menjadi [4,11]
 * Jika l = [0,1,0,3,0,2,2,0], maka setelah mergeList(&l), l menjadi [1,3,4]
 *
 * Hint:
 * - Gunakan variabel untuk menampung hasil penjumlahan sementara
 * - Jangan lupa update FIRST(l) di akhir!
 */
void mergeList(List *l) {
	if (isEmpty(*l)) return;

	Node* current = *l;
	Node* newList;
	CreateList(&newList);
	Node* tail = NULL;

	int sum = 0;
	current = current->next;

	while (current != NULL) {
		if (current->info == 0) {
			Node* newNode = (Node*)malloc(sizeof(Node));
			if (newNode == NULL) {
				return;
			}
			newNode->info = sum;
			newNode->next = NULL;

			if (newList == NULL) {
				newList = newNode;
				tail = newNode;
			} else {
				tail->next = newNode;
				tail = newNode;
			}

			sum = 0; 
		} else {
			sum += current->info;
		}
		current = current->next;
	
	}

	if (tail != NULL) {
		tail->next = NULL;
	}

	*l = newList;
}