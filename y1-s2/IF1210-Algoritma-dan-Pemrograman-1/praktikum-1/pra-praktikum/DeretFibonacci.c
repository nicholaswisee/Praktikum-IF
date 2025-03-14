#include <stdio.h>

int main() {

    int N;
    int j = 0;
    int k = 1;
    int temp;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        printf("%d\n", j);
        temp = j + k;
        j = k;
        k = temp;
    }
    
    return 0;
}