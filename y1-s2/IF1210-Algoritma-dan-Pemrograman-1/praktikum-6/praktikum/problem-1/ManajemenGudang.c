#include "liststatik.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    ListStatik Gudang;
    CreateListStatik(&Gudang);
    int N;
    int berat, idx;

    while (N != -1) {
        scanf("%d", &N);
        switch(N) {
            case 1: {
                scanf("%d %d", &berat, &idx);
                if (idx < 0 || idx > listLength(Gudang) || isFull(Gudang)) {
                    printf("Aw, gabisa ngelakuin aksi itu\n");
                    printList(Gudang);
                    printf("\n");

                    break;
                } else {  
                    insertAt(&Gudang, berat, idx);
                    printList(Gudang);
                    printf("\n");

                    break;
                }
            } 
            case 0: {
                scanf("%d", &idx);
                if (!isIdxEff(Gudang, idx) || isEmpty(Gudang)) {
                    printf("Aw, gabisa ngelakuin aksi itu\n");
                    printList(Gudang);
                    printf("\n");


                    break;
                } else {
                    deleteAt(&Gudang, &berat, idx);  
                    printList(Gudang);
                    printf("\n");

                    break;
                }
            }
            case -1: {
                break;
            }
            default: {
                printf("Aw, gabisa ngelakuin aksi itu\n");
                printList(Gudang);
                printf("\n");

                break;
            }
        }
    }
    
    return 0;
}