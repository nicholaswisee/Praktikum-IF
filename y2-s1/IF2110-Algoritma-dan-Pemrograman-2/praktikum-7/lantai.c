#include <stdio.h>

int countTiles(int n) {
    if (n == 1) return 1;
    else if (n == 2) return 2;
    else return countTiles(n - 1) + countTiles(n - 2);    
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", countTiles(n));
}