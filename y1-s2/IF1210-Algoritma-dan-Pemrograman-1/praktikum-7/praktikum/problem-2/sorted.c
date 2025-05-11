#include <stdio.h>
#include "listkontigu.h"
#include "Boolean.h"

boolean isSorted (ListKontigu L) {
    int len = listLength(L);
    for (int i = 0; i < len - 1; i++) {
        if (L.contents[i] > L.contents[i + 1]) return FALSE;
    }
    return TRUE;
}

int main() {
    ListKontigu L;
    readList(&L);

    ListKontigu copyL;

    int len = listLength(L);
    int lastId = lastIdx(L);
    int revStart;

    if (isSorted(L)) {
        printf("YA\n");
        return 0;
    }

    for (int i = 0; i < len - 1; i++) {
        if (L.contents[i] > L.contents[i + 1]) {
            revStart = i;
            break;
        }
    }
    while (revStart < lastId) {
        copyList(L, &copyL);

        int lastindex = lastId;
        for (int j = revStart; j <= lastId; j++) {
            copyL.contents[j] = L.contents[lastindex--]; 
        }

        if (isSorted(copyL)) {
            printf("YA\n");
            printf("%d %d\n", revStart, lastId);
            return 0;
        } else {
            lastId--;
        }
    }

    if (isSorted(copyL)) {
        printf("YA\n");
        printf("%d %d\n", revStart, lastId);
    } else {
        printf("TIDAK\n");
    }

    return 0;
}