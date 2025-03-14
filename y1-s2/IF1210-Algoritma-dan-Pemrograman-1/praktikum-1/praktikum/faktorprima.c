#include <stdio.h> 
#include <string.h>

int main() {

    int N, factor, count, factorcount = 0;
    char output[16] = "";
    char tempstring[16] = "";

    scanf("%d", &N);

    for (int i = 2; i <= N; i++) {
        count = 0;
        if (N % i == 0) {
            factorcount += 1;
            while (N % i == 0) {
                N /= i;
                count += 1;
            }
            factor = i;
            if (factorcount == 1) {
                if (count == 1) {
                    printf("%d", factor);
                } else {
                    printf("%d^", factor);
                    printf("%d", count);
                }
            } else {
                if (count == 1) {
                    printf(" * %d", factor);
                } else {
                    printf(" * %d^", factor);
                    printf("%d", count);
                }
            }
        }

    }

    printf("\n");
    return 0;
}