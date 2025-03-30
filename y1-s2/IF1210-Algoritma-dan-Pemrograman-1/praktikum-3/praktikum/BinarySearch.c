#include <stdio.h>

// int binarySearch(int*    int long size, long long searched) {
//     int found = 0;
//     for (int i = 0; i < size;++) {
//         if (arr[i] == searched){
//             found = 1;
//             return i;
//         } 
//     }

//     if (found == 0) return -1;
// }

int binarySearch(int arr[], int left, int right, int target) {
    int middle = (left + right) / 2;

    if (left > right) {
        return -1;
    }

    if (arr[middle] == target) return middle;

    else if (arr[middle] > target) {
        return binarySearch(arr, left, middle - 1, target);
    } else {
        return binarySearch(arr, middle + 1, right, target);
    }
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