#include "prioritas.h"
#include "queue.h"

void prioritizeValue(Queue *q, int x) {
    Queue tempQueue, endQueue;
    CreateQueue(&tempQueue);
    CreateQueue(&endQueue);
    
    int idx = q->idxHead;
    int len = length(*q);

    for (int i = 0; i < len; i++) {
        if (q->buffer[idx] == x) {
            enqueue(&endQueue, q->buffer[idx]);
        } else {
            enqueue(&tempQueue, q->buffer[idx]);
        }

        idx = (idx + 1) % CAPACITY;

    }

    int tempLen = length(tempQueue);
    idx = tempQueue.idxHead;

    for (int i = 0; i < tempLen; i++) {
        enqueue(&endQueue, tempQueue.buffer[idx]);
        idx = (idx + 1) % CAPACITY;
    }


    for (int j = 0; j < CAPACITY; j++) {
        q->buffer[j] = endQueue.buffer[j];
        q->idxHead = endQueue.idxHead;
        q->idxTail = endQueue.idxTail;
    }
}