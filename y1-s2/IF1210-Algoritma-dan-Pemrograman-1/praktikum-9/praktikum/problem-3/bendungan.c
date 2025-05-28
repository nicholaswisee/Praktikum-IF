#include <stdio.h>
#include "stack.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}


int min(int a, int b) {
    return (a < b) ? a : b;
}

int hitungBendungan(int waterArr[], int len) {
    if (len <= 2 ) return 0;

    int leftHeight[len];
    int rightHeight[len];

    // Isi array kiri
    leftHeight[0] = waterArr[0];
    for (int i = 1; i < len; i++) {
        leftHeight[i] = max(leftHeight[i - 1], waterArr[i]);
    }

    rightHeight[len - 1] = waterArr[len - 1];
    for (int i = len - 2; i >= 0; i--) {
        rightHeight[i] = max(rightHeight[i + 1], waterArr[i]);
    }

    int total = 0;
    for (int i = 0; i < len; i++) {
        int waterLevel = min(leftHeight[i], rightHeight[i]);
        if (waterLevel > waterArr[i]) {
            total += waterLevel - waterArr[i];
        }
    }

    return total;
}

int main() {
    int N;

    scanf("%d", &N);

    int water[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &water[i]);
    }

    int result = hitungBendungan(water, N);
    
    printf("%d\n", result);
    return 0;
}