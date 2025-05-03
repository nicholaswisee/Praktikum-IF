#include "listdin.h"
#include <stdio.h>
#include <math.h>
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
    ListDin LDiff;
    readList(&L);
    
    CreateListDin(&LDiff, listLength(L) * (listLength(L)));
    
    int absDiff;
    for (int i = 0; i < L.nEff; i++) {
        for (int j = 0; j < L.nEff; j++) {
            if (j != i) {
                absDiff = abs(L.buffer[i] - L.buffer[j]);
                    LDiff.buffer[LDiff.nEff] = absDiff;
                    LDiff.nEff++;
            }
        }
    }    

    if (LDiff.nEff == 0) {
        printf("0\n"); 
    } else {
        int finalGCD = LDiff.buffer[0];

        for (int i = 1; i < LDiff.nEff; i++) {
            finalGCD = GCD(finalGCD, LDiff.buffer[i]);
        }

        printf("%d\n", finalGCD);
    }
    dealocateList(&LDiff);
    dealocateList(&L);
    return 0;
}