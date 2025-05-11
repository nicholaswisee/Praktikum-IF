#include <stdio.h>
#include"Boolean.h"
#include "listkontigu.h"

boolean cekAturan(int x, int y, int z) {
    if (x < z && z < y) return TRUE;
    return FALSE;
}

int main() {
    ListKontigu l;
    CreateList(&l);
    readList(&l);

    int aman = FALSE;
    int len = listLength(l);
    for (int i = 0; i < len - 2; i++) {
        for (int j = i + 1; j < len - 1; j++) {
            for (int k = j + 1; k < len; k++) {
                if (cekAturan(l.contents[i], l.contents[j], l.contents[k])) {
                    aman = TRUE;
                    break;
                }
            }
            if (aman) break;
        }
    }

    if (aman) printf("Nyalakan");
    else printf("Santai");
    printf("\n");

    return 0;
}