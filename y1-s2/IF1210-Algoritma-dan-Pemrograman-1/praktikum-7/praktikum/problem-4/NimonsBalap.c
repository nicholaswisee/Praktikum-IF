#include <stdio.h>
#include"Boolean.h"
#include "listkontigu.h"


int main(){
    ListKontigu l;
    ListKontigu lOut;
    int k;

    ElType doll;
    readList(&l);

    scanf("%d", &k);
    CreateList(&lOut);

    int firstId = firstIdx(l);
    int len = listLength(l);

    int max;
    int idxMax;
    int count = 0;

    int temp;
    while (count < len - k + 1) {
        idxMax = firstIdx(l);
        for (int i = firstIdx(l); i < firstIdx(l) + k; i++) {
            if (l.contents[idxMax] < l.contents[i]) idxMax = i;
        }
        insertLast(&lOut, l.contents[idxMax]);
        deleteFirst(&l, &temp);
        count++;
    }

    printList(lOut);
    printf("\n");
    return 0;
}
