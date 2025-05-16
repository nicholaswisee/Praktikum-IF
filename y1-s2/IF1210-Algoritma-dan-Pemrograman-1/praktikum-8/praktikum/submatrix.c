#include <stdio.h>
#include "matrix.h"
#include "Boolean.h"

int main() {
    int N, M, K, X;
    Matrix m, subM;
    int sum, count = 0;

    scanf("%d %d %d %d", &N, &M, &K, &X);
    readMatrix(&m, N , M);

    for (int i = 0; i <= m.rowEff - K; i++) {
        for (int j = 0; j <= m.colEff - K; j++){
            createMatrix(K, K, &subM);
            int curRow = 0, curCol = 0;
            sum = 0;

            for (int k = 0; k < K; k++) {
                for (int l = 0; l < K; l++) {
                    subM.mem[k][l] = m.mem[k + i][l + j];
                    sum += m.mem[k + i][l + j];
                }
            }

            if (sum <= X) count++;
        }
    }
    printf("%d\n", count);
    return 0;
}