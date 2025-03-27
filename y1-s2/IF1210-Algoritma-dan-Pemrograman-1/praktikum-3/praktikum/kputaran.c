#include <stdio.h>


int main() {

    int N, k;

    scanf("%d", &N);
    scanf("%d", &k);
    int jumlah_rotasi = k % N;

    int barisan[N];

    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        barisan[i] = num;
    }


        int temp[N], output[N];

        for (int y = 0; y < N; y++) {
            temp[y] = barisan[y];
            output[y] = barisan[y];
        }

        for (int p = 1; p <= jumlah_rotasi; p++) {
            for (int q = 0; q < N; q++) {
                if (q - 1 >= 0) {
                    output[q] = temp[q - 1];
                } else {
                    output[q] = temp[N - 1];
                }
            
            }
            for (int r = 0; r < N; r++) {
                temp[r] = output[r];
            }

        }


        for (int z = 0; z < N; z++) {
            printf("%d", output[z]);
            if (z < N - 1) printf(" ");
        }
        printf("\n");

    return 0;
}