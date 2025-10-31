#include <stdio.h>

int countComb(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else if (n == 2) return 2;
    else return n + countComb(n-1) + countComb(n-2) - 1;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", countComb(n));
}