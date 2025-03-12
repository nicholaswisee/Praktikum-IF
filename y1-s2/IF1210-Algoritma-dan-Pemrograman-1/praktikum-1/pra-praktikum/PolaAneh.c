#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);    

    int mid = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((j == mid - i) || (j == mid + i ) || (j == i - mid) || (j == 3 * (mid) - i))
                printf("*");
            else    
                printf(".");
        }
        printf("\n");
    }

    return 0;
}