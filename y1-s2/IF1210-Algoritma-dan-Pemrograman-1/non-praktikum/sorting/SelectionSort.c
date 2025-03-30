#include <stdio.h>

int main() {

    int Temp, iMin;
    int T[6] = {35, 12, 10, 60, 30, 25};


    for (int i = 0; i < 6; i++) {
        iMin = i;

        for (int Pass = i + 1; Pass < 6; Pass++) {
            if (T[Pass] < T[iMin]) {
                iMin = Pass;
            }
        }

        Temp = T[iMin];
        T[iMin] = T[i];
        T[i] = Temp;

    }

    printf("[ ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", T[i]);
    }

    printf("]");
    printf("\n");

    return 0;
}