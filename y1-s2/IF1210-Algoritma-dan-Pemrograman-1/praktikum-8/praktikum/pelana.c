#include <stdio.h>
#include "matrix.h"
#include "Boolean.h"

int main() {

    int R, K;
    Matrix m;
    int count = 0;

    boolean RTrue, KTrue;

    scanf("%d %d", &R, &K);
    readMatrix(&m, R, K);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < K; j++) {
            RTrue = TRUE;
            KTrue = TRUE;
            for (int k = 0; k < K; k++) {
                if (ELMT(m, i, j) > ELMT(m, i, k)) {
                    KTrue = FALSE;
                    break;
                };
            }

            for (int r = 0; r < R; r++) {
                if (ELMT(m, i, j) < ELMT(m, r, j)) {
                    RTrue = FALSE;
                    break;
                };
            }

            if (KTrue && RTrue) {
                printf("(%d,%d,%d)\n", i, j, ELMT(m, i ,j));
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}