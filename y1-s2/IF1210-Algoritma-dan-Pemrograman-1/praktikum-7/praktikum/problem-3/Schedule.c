#include "Boolean.h"
#include <stdio.h>
#include "listkontigu.h"

int main() {
    ListKontigu l;
    int N;

    scanf("%d", &N);

    int listEl;
    CreateList(&l);
    int idxGreater;
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &listEl);

        if (i == 0) insertFirst(&l, listEl);
        else {
            idxGreater = IDX_UNDEF;
            for (int j = 0; j < listLength(l); j++) {
                if (l.contents[j] > listEl) {
                    idxGreater = j;
                    break;
                }
            }

            if (idxGreater == IDX_UNDEF) insertLast(&l, listEl);
            else {
                insertAt(&l, listEl, idxGreater);
            }
        }
        printList(l);
        printf("\n");
    }

    return 0;
}