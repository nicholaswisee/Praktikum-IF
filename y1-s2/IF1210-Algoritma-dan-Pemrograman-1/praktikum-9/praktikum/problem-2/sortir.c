#include "queue.h"
#include <stdio.h>

int main() {

    int N;
    scanf("%d", &N);

    Queue q;
    int temp;

    CreateQueue(&q);
    
    for (int i = 0; i < N; i++) {
        int input;
        scanf("%d", &input);

        enqueue(&q, input);
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (q.buffer[j] < q.buffer[j + 1]) {
                temp = q.buffer[j];
                q.buffer[j] = q.buffer[j + 1];
                q.buffer[j + 1] = temp;
            }
        }
    }
    
    displayQueue(q);


    return 0;
}