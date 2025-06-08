#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "listlinier.h"

boolean isIn(List l, ElType val) {
	if (l == NULL) return 0;
	
	Node* current = l;
	while (current != NULL) {
		if (current->info == val) return 1;

		current = current->next;
	}

	return 0;
}

void dealokasiList(List *l) {
    Address p_current = FIRST(*l); // Dapatkan pointer ke elemen pertama
    Address p_next;

    while (p_current != NULL) {
        p_next = NEXT(p_current); // Simpan pointer ke elemen berikutnya
        free(p_current);          // Bebaskan memori elemen saat ini
        p_current = p_next;       // Pindah ke elemen berikutnya
    }

    *l = NULL; // Setelah semua node dibebaskan, set pointer list utama ke NULL
}

void insertSorted(List *l, ElType val) {
    if (l == NULL) return;
	Node* newVal = newNode(val);
	
	// Jika insert sebagai elemen pertama
	if (*l == NULL || val < (*l)->info) {
		newVal->next = *l;
		*l = newVal;
		return;
	}
	
	Node* current = *l;
	Node* prev = NULL;

	while (current != NULL && current->info < val) {
		prev = current;
		current = current->next;
	}

	prev->next = newVal;
	newVal->next = current;
}

List getUnion(List l1, List l2){
	if (l1 == NULL && l2 == NULL) return NULL;

    List resultList;
	CreateList(&resultList);
	
	if (l1 == NULL) {
		Node* current = l2;
		while (current != NULL) {
			insertLast(&resultList, current->info);
			current = current->next;
		}		
		return resultList;
	}
	if (l2 == NULL) {
		Node* current = l1;
		while (current != NULL) {
			insertLast(&resultList, current->info);
			current = current->next;
		}		
		return resultList;
	}

	Node* current = l1;
	while (current != NULL) {
		insertLast(&resultList, current->info);		
		current = current->next;
	}

	current = l2;
	while (current != NULL) {
		if (!isIn(resultList, current->info)) {
			insertLast(&resultList, current->info);
		} 
		current = current->next;
	}

	return resultList;
}

List getIntersect(List l1, List l2){
    List resultList;
	CreateList(&resultList);

	Node* current = l1;
	while (current != NULL) {
		if (isIn(l2, current->info)) {
			insertLast(&resultList, current->info);
		}

		current = current->next;
	}

	return resultList;
}

void getData(List *Union, List *Irisan){
    int N;
	scanf("%d", &N);
	List resultUnion, resultIntersect;
	CreateList(&resultUnion);
	CreateList(&resultIntersect);

	for (int i = 0; i < N; i++) {
		int len;
		scanf("%d", &len);

		List tempList;
		CreateList(&tempList);
		for (int j = 0; j < len; j++) {
			int element;
			scanf("%d", &element);
			insertLast(&tempList, element);
		}

		// Prevent memory leak dengan re-assign dan dealokasi
		List prevUnion = resultUnion;
		resultUnion = getUnion(resultUnion, tempList);
		if (i > 0) dealokasiList(&prevUnion);

		if (i == 0) {
			Node *current = tempList;
			while (current != NULL) {
				insertLast(&resultIntersect, current->info);
				current = current->next;
			}
		} else {
			List prevIntersect = resultIntersect; // Prevent memory leak dengan re-assign dan dealokasi
			resultIntersect = getIntersect(resultIntersect, tempList);
			dealokasiList(&prevIntersect);
		}
		dealokasiList(&tempList);
	}

	List sortedUnion, sortedIntersect;
	CreateList(&sortedUnion);
	CreateList(&sortedIntersect);

	Node* current = resultUnion;
	while (current != NULL) {
		insertSorted(&sortedUnion, current->info);
		current = current->next;
	}

	current = resultIntersect;
	while (current != NULL) {
		insertSorted(&sortedIntersect, current->info);
		current = current->next;
	}

	dealokasiList(&resultUnion);
	dealokasiList(&resultIntersect);

	*Union = sortedUnion;
	*Irisan = sortedIntersect;
}