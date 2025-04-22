#include <stdio.h>

int main() {

    int Temp;
    int T[6] = {35, 12, 10, 60, 30, 80};
    int N = 6;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            if (T[j] > T[j+1]) {
                Temp = T[j];
                T[j] = T[j+1];
                T[j+1] = Temp;
            }
        }
    }
    
    printf("[ ");   

    for (int i = 0; i < 6; i++) {
        printf("%d ", T[i]);
    }

    printf("]");
    printf("\n");

    return 0;

}
