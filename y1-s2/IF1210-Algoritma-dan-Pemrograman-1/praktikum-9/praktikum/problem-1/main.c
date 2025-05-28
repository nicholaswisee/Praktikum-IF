#include "queue.h"
#include "prioritas.h"
#include <stdio.h>

int main() {
    Queue Q;
    CreateQueue(&Q);
    int N, input;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &input);
        enqueue(&Q, input);
    }
    
    int val;
    scanf("%d", &val);

    prioritizeValue(&Q, val);

    return 0;
}