#include <stdio.h>

int binarySearch(int* arr, long long size, long long searched) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == searched){
            found = 1;
            return i;
        } 
    }

    if (found == 0) return -1;
}

// int BinarySearch(int arr[], int N, int target) {
//     int found = 0;
//     int left = 0, right = N - 1;
//     while (left <= right && found = 0) {
//         if (arr[left] == )
//     }
// }

int main() {
    long long N, Q;

    scanf("%lld", &N);
    int list_angka[N];

    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        list_angka[i] = num;
    }

    scanf("%lld", &Q);

    int list_dicari[Q];

    for (int j = 0; j < Q; j++) {
        int num;
        scanf("%d", &num);
        list_dicari[j] = num;
    }

    printf("[");
    for (int j = 0; j < Q; j++) {
        int dicari = list_dicari[j];
        int index = binarySearch(list_angka, N, dicari);
        printf("%d", index);
        if (j != Q - 1) {
            printf(", ");
        }
        

    }
    printf("]\n");



    return 0;
}