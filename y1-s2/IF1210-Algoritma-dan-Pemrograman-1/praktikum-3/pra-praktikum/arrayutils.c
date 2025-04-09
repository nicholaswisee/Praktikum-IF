#include <stdio.h>
#include "arrayutils.h"

void sort(int arr[] , int n){
    int temp;
    //izin bubble sort ketua!
    for (int i = 0 ; i < n; i++){
        for (int j = 0 ; j < n - 1 - i; i++) {
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int find(int arr[], int n, int target){
    int found;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) found = i;
    }
    found = -1;

    return found;

}

double calculateAverage(int arr[], int n){
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum / n;

}

int findMedian(int arr[], int n){
    sort(arr, n);

    int median;

    if (n % 2 == 1) {
        median = arr[n/2];
    } else {
        median = (arr[n/2 - 1] + arr[n/2]) / 2;
    }
    
    return median;
}

int findMode(int arr[], int n){
    int el;
    int modus = 0, max = 0, count;

    for (int i = 0; i < n; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[j]) count++;
        }
        if (count > max) max = count;
    }

}

int findMax(int arr[], int n){
    int max = arr[0];
    for (int i = 0; i < n; i++){
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int findMin(int arr[], int n){
    int min = arr[0];
    for (int i =0; i < n; i++){
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

void reverseArray(int arr[], int n){
    int kiri = 0, kanan = n-1;

    while (kiri < kanan){
        int temp = arr [kiri];
        arr[kiri] = arr[kanan] ;
        arr[kanan] = temp;

        kiri++; 
        kanan-- ; 
    }
}