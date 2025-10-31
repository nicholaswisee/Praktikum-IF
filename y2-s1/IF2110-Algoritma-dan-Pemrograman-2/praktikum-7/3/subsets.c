#include <stdio.h>

// [1,2,3,4] -> [], [1], [2] ... [1,2], [1,3], [1,4]

void printArr(int arr[], int length) {
    printf("[");
    for (int i = 0; i < length; i++) {
        printf("%d");
        if (i != length - 1) printf(",");
    }

    printf("]\n");
}



void printSubsets(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            int tempArr[i];
                

        }
    }
}

int main() {
    int len;
    int temp;

    scanf("%d", len);
    int arr[len];

    for (int i = 0; i < len; i++) {
        scanf("%d", temp);
        arr[i] = temp;
    }
}