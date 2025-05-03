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

int findGCD(ListDin L) {

    if (L.nEff <= 1) {
        return 0; 
    }
    
    int result = 0;
    int found = 0;
    
    for (int i = 0; i < L.nEff - 1 && !found; i++) {
        for (int j = i + 1; j < L.nEff && !found; j++) {
            int diff = abs(L.buffer[i] - L.buffer[j]);
            if (diff > 0) {
                result = diff;
                found = 1;
            }
        }
    }
    
    if (!found) {
        return 0;
    }
    
    for (int i = 0; i < L.nEff; i++) {
        for (int j = i + 1; j < L.nEff; j++) {
            int diff = abs(L.buffer[i] - L.buffer[j]);
            if (diff > 0) {
                result = GCD(result, diff);
    
                if (result == 1) {
                    return 1;
                }
            }
        }
    }
    
    return result;
}

int main() {
    ListDin L;
    int initialCapacity = 100000;
    CreateListDin(&L, initialCapacity);
    
    readList(&L);
    
    int result = findGCD(L);
    
    printf("%d\n", result);
    
    dealocateList(&L);
    
    return 0;
}