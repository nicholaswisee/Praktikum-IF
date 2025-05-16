#include <stdio.h>
#include "matrix.h"
#include "Boolean.h"

int main() {
    int N;
    scanf("%d", &N);
    Matrix m;
    boolean brity;
    readMatrix(&m, N , N);

    if (N == 1) {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < N; i++) {
        brity = TRUE;
        for (int j = 0; j < N; j++) {
            if (j != i && ELMT(m, i, j) == 1) {
                brity = FALSE;
            }

            if (brity == FALSE) break;
        }
        
        if (brity == FALSE) continue;
        
        for (int k = 0; k < N; k++) {
            if (ELMT(m, k, i) != 1 && k != i) {
                brity = FALSE;
            }
        }

        if (brity)  {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}