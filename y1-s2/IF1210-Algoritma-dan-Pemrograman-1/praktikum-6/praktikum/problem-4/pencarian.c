#include "listdin.h"
#include "Boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int N;
    scanf("%d", &N);
    
    ListDin PrevList;
    ListDin NextList;
    ListDin Selisih;
    
    CreateListDin(&PrevList, 5);
    CreateListDin(&NextList, 5);
    CreateListDin(&Selisih, 5);
    
    if (N < 2) {
        printf("Invalid input\n");
        dealocateList(&PrevList);
        dealocateList(&NextList);
        dealocateList(&Selisih);
        return 0;
        }
    
    for (int i = 0; i < 5; i++) {
        insertLast(&PrevList, 0);
        insertLast(&Selisih, 0);
        insertLast(&NextList, 0);
    }

    for (int i = 0; i < 5; i++) {
        int time;
        scanf("%d", &time);
        PrevList.buffer[i] = time;
    }
    
    for (int i = 1; i < N; i++)  {
        for (int nimon = 0; nimon < 5; nimon++) {
            int time;
            scanf("%d", &time);
            NextList.buffer[nimon] = time;
        }
        for (int nimon = 0; nimon < 5; nimon++) {
            Selisih.buffer[nimon] += NextList.buffer[nimon] - PrevList.buffer[nimon];
        }
        copyList(NextList, &PrevList);
    }
        
    
    int min, max;
    extremeValues(Selisih, &max, &min);

    int idx;
    for (int j = 0; j < 5; j++) {
        if (Selisih.buffer[j] == min) {
            idx = j;
            break;
        }
    }

    switch(idx) {
        case 0:
            printf("Kebin\n");
            break;
        case 1:
            printf("Stewart\n");
            break;
        case 2:
            printf("Pop\n");
            break;
        case 3:
            printf("Luiy\n");
            break;
        case 4:
            printf("Toto\n");
            break;
}

    dealocateList(&PrevList);
    dealocateList(&NextList);
    dealocateList(&Selisih);

    return 0;
}