#include <stdio.h>


int main() {

    unsigned long long int N, T, X, increment;

    scanf("%llu", &N);
    scanf("%llu", &T);
    scanf("%llu", &X);

    increment = N * X;
    for (int i = 0; i <=T; i++) {
        if (i > 0) {
            N += increment;
            increment *= X;
        }
    }
    printf("Terdapat %llu Virus Nimons Gila pada jam ke-%llu\n", N, T);

    return 0;
}   