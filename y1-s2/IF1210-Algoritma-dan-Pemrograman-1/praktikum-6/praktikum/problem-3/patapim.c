#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GCD(b, a % b);
    }
}

int main() {
    ListDin L;
    CreateListDin(&L, 100000);
    int result, min, max;

    readList(&L);
    compressList(&L);

    extremeValues(L, &max, &min);

    result = L.buffer[0] - min;
    for (int i = 1; i < L.nEff; i++) {
        if (L.buffer[i] != min) {
            result = GCD(L.buffer[i] - min, result);
        }
    }

    dealocateList(&L); 
    printf("%d\n", result);

    return 0;
}