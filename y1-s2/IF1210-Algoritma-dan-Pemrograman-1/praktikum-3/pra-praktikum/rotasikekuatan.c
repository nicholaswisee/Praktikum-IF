#include <stdio.h>

int main() {

    int element, rotasi, jumlah_rot;

    scanf("%d", &element);
    scanf("%d", &rotasi);

    int barisan[element];
    int langkah[rotasi];

    for (int i = 0; i < element; i++) {
        int num;
        scanf("%d", &num);
        barisan[i] = num;
    }

    for (int j = 0; j < rotasi; j++) {
        int rot;
        scanf("%d", &rot);
        langkah[j] = rot;
    }

    for (int k = 0; k < rotasi; k++) {
        jumlah_rot = langkah[k];
        int temp[element], output[element];

        for (int y = 0; y < element; y++) {
            temp[y] = barisan[y];
            output[y] = barisan[y];
        }

        for (int p = 1; p <= jumlah_rot; p++) {
            for (int q = 0; q < element; q++) {
                if (q - 1 >= 0) {
                    output[q] = temp[q - 1];
                } else {
                    output[q] = temp[element - 1];
                }
            
            }
            for (int r = 0; r < element; r++) {
                temp[r] = output[r];
            }
        }

        printf("[");
        for (int z = 0; z < element; z++) {
            printf("%d", output[z]);
            if (z + 1 < element) {
                printf(", ");
            }
        }
        printf("]\n");
        
    }

    return 0;
}