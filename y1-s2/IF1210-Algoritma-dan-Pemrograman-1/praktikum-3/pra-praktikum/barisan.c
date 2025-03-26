#include <stdio.h>

int GCD(int* arr, int size) {
    if (size == 0) return 0;
    if (size == 1) return arr[0];
    
    int result = arr[0];
    for (int i = 1; i < size; i++) {
        int a = result;
        int b = arr[i];
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        result = a;
        if (result == 1) break; // GCD can't be smaller than 1
    }
    //Euclidean Algorithm for GCD
    return result;
}

int LCM(int* arr, int size) {
    if (size == 0) return 0;
    if (size == 1) return arr[0];

    int multiple = arr[0];
    for (int i = 1; i < size; i++) {
        int a = multiple;
        int b = arr[i];


        int gcd = a;
        int temp = b;
        while (temp != 0) {
            int mod = gcd % temp;
            gcd = temp;
            temp = mod;
        }

        multiple = a * b / gcd;
    }

    return multiple;

}

int hitungSkorMax(int* arr, int size) {
    if (size == 0) return 0;
    if (size == 1) return arr[0] * arr[0];
    
    int max_score = 0;
    
    int original_gcd = GCD(arr, size);
    int original_lcm = LCM(arr, size);
    max_score = original_gcd * original_lcm;
    
    for (int i = 0; i < size; i++) {
 
        int temp_arr[size - 1];
        int index = 0;
        for (int j = 0; j < size; j++) {
            if (j != i) {
                temp_arr[index++] = arr[j];
            }
        }
        
        int current_gcd = GCD(temp_arr, size - 1);
        int current_lcm = LCM(temp_arr, size - 1);
        int current_score = current_gcd * current_lcm;
        
        if (current_score > max_score) {
            max_score = current_score;
        }
    }
    
    return max_score;
}

int main() {
    int N, num;

    scanf("%d", &N);
    if (N == 0) return 0;

    int A[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        A[i] = num;
    }

    printf("%d\n", hitungSkorMax(A, N));

    return 0;
}