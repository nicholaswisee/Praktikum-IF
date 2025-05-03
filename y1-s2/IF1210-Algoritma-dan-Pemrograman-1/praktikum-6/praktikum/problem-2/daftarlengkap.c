#include <stdio.h>
#include "Boolean.h"
#include "liststatik.h"

int main() {
    ListStatik listA, listB, listC;
    int N, M, i, val;
    
    CreateListStatik(&listA);
    CreateListStatik(&listB);
    CreateListStatik(&listC);
    
    scanf("%d", &N);
    
    for (i = 0; i < N; i++) {
        scanf("%d", &val);
        insertLast(&listA, val);
    }
    
    scanf("%d", &M);
    
    for (i = 0; i < M; i++) {
        scanf("%d", &val);
        insertLast(&listB, val);
    }
    
    int idxA = 0, idxB = 0;
    ElType elemA, elemB;
    
    if (isEmpty(listA)) {
        for (i = 0; i < listLength(listB); i++) {
            insertLast(&listC, ELMT(listB, i));
        }
    } else if (isEmpty(listB)) {
        for (i = 0; i < listLength(listA); i++) {
            insertLast(&listC, ELMT(listA, i));
        }
    } else {
        while (idxA < listLength(listA) && idxB < listLength(listB)) {
            elemA = ELMT(listA, idxA);
            elemB = ELMT(listB, idxB);
            
            if (elemA <= elemB) {
                insertLast(&listC, elemA);
                idxA++;
            } else {
                insertLast(&listC, elemB);
                idxB++;
            }
        }
        
        while (idxA < listLength(listA)) {
            insertLast(&listC, ELMT(listA, idxA));
            idxA++;
        }
        
        while (idxB < listLength(listB)) {
            insertLast(&listC, ELMT(listB, idxB));
            idxB++;
        }
    }
    
    printList(listC);
    printf("\n");
    
    return 0;
}