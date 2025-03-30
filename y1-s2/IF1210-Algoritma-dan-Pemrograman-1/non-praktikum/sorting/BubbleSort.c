#include <stdio.h>

int main() {

    int Temp;
    int T[6] = {35, 12, 10, 60, 30, 25};
    int N = 6;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (T[j] > T[j + 1]) {
                Temp = T[j + 1];
                T[j+1] = T[j];
                T[j] = Temp;
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
