#include <stdio.h>

int main() {

    int Temp;
    int T[6] = {35, 12, 10, 60, 30, 25};

    for (int Pass = 1; Pass < 6; Pass++) {
        Temp = T[Pass];
        int i = Pass - 1; //previous element

        while (Temp < T[i] && i >= 0) {
            T[i+1] = T[i];
            i--;
        }

        T[i+1] = Temp;
    
        printf("[ ");
        for (int i = 0; i < 6; i++) {
            printf("%d ", T[i]);
        }
    
        printf("]");
        printf("\n");
    }


    return 0;
}