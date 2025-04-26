#include "time.h"
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    long timeDiff;

    TIME tempTime1;
    TIME tempTime2;

    long palingAwal = 86400;
    long palingAkhir = 0;

    for (int i = 0; i < N; i++) {
        printf("[%d]\n", i + 1);

        BacaTIME(&tempTime1);
        BacaTIME(&tempTime2);
        
        //If first time read is greater, switch values
        if (TGT(tempTime1, tempTime2)) {
            TIME temp;
            temp = tempTime1;
            tempTime1 = tempTime2;
            tempTime2 = temp;
        }

        //Set new earliest/latest time
        if (TIMEToDetik(tempTime1) < palingAwal) {
            palingAwal = TIMEToDetik(tempTime1);
        }
        if (TIMEToDetik(tempTime2) > palingAkhir) {
            palingAkhir = TIMEToDetik(tempTime2);
        }

        timeDiff = Durasi(tempTime1, tempTime2);
        printf("%ld\n", timeDiff);
    }

    TulisTIME(DetikToTIME(palingAwal));
    printf("\n");
    TulisTIME(DetikToTIME(palingAkhir));
    printf("\n");

    return 0;
} 