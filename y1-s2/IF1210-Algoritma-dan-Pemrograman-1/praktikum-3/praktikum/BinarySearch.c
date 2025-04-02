#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    int result = -1;

    while (left <= right) {
        int middle = left + (right - left) / 2;  
        
        if (arr[middle] == target) {
            result = middle;
            right = middle - 1;
        }
        else if (arr[middle] > target) {
            right = middle - 1;  
        }
        else {
            left = middle + 1;  
        }
    }
    return result;  // Target not found
}

int main() {
    int N, Q;

    scanf("%d", &N);
    int list_angka[N];

    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        list_angka[i] = num;
    }

    scanf("%d", &Q);

    int list_dicari[Q];

    for (int j = 0; j < Q; j++) {
        int num;
        scanf("%d", &num);
        list_dicari[j] = num;
    }

    printf("[");
    for (int j = 0; j < Q; j++) {
        int dicari = list_dicari[j];
        int index = binarySearch(list_angka, 0, N - 1, dicari);

        printf("%d", index);
        if (j != Q - 1) {
            printf(", ");
        }
        

    }
    printf("]\n");



    return 0;
}