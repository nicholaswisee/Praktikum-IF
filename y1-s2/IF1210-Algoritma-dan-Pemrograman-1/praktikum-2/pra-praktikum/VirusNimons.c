#include <stdio.h>


int main() {

    int N, T, X, increment;

    scanf("%d", &N);
    scanf("%d", &T);
    scanf("%d", &X);

    increment = N * X;
    for (int i = 0; i <=T; i++) {
        if (i > 0) {
            N += increment;
            increment *= X;
        }
    }
    printf("Terdapat %d Virus Nimons Gila pada jam ke-%d\n", N, T);

    return 0;
}