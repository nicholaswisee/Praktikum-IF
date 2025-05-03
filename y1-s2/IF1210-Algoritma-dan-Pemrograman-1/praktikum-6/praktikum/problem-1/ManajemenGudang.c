#include "liststatik.h"
#include <stdio.h>

int main() {
    ListStatik Gudang;
    CreateListStatik(&Gudang);
    int N = 0;
    int berat, idx;

    while (N != -1) {
        scanf("%d", &N);
        switch(N) {
            case 1: {
                scanf("%d %d", &berat, &idx);
                if (!isIdxValid(Gudang, idx) || isFull(Gudang)) {
                    printf("Aw, gabisa ngelakuin aksi itu\n");
                    printList(Gudang);
                    printf("\n");
                    continue;
                } else {  
                    insertAt(&Gudang, berat, idx);
                    printList(Gudang);
                    printf("\n");
                    break;
                }
            } 
            case 0: {
                scanf("%d", &idx);
                if (!isIdxEff(Gudang, idx)) {
                    printf("Aw, gabisa ngelakuin aksi itu\n");
                    printList(Gudang);
                    printf("\n");

                    continue;
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