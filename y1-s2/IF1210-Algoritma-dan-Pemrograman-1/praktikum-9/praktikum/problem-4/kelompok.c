#include <stdio.h>
#include "stack.h"

int findMax(int arr[], int len, int startIdx) {
    int max = arr[startIdx];
    for (int i = startIdx; i < startIdx + len; i++) {
        if (max < arr[i]) max = arr[i];
    }

    return max;
}

int main() {
    int N, input;
    Stack S;
    int totalSum = 0;

    CreateEmpty(&S);
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &input);
        Push(&S, input);
    }

    for (int windowSize = 1; windowSize <= N; windowSize++) {
        for (int j = 0; j <= N - windowSize; j++) {
            totalSum += findMax(S.T, windowSize, j);
        }
    }

    printf("%d\n", totalSum);

    return 0;
}