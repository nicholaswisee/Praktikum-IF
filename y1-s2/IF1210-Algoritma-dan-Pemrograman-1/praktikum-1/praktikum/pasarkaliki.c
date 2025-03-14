#include <stdio.h>
#include <math.h>

int main() {

    double N;
    double comb;

    scanf("%lf", &N);

    for (double n = 0; n < N; n++) {
        for (double k = 0; k <= n; k++){
            if (k == 0) {
               comb = (tgamma(n + 1)) / ((tgamma(k + 1) * tgamma(n-k + 1)));
            } else {
                comb *= (n - (k - 1))/(k);
            }
            printf("%.0lf ", comb); 

        }
        printf("\n");
    }

    printf("\n");
    return 0;
}