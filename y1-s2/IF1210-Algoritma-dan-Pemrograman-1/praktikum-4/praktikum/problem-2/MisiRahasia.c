#include <stdio.h>
#include <stdlib.h>
// #include "tester.h"

#define MAX_MISSION 1000


/* Tulis kode disini jika perlu */
typedef struct {
    int nimonId;
    int success;
    int missionValue;
} Mission;


int bubbleSortChecker(Mission *a, Mission *b) {
    if (a->success != b->success) {
        if (a->success <= b->success) {
            return 0;
        } else {
            return 1;
        }
    }
    if (a->missionValue != b->missionValue) {
        if (a->missionValue <= b->missionValue) {
            return 0;
        } else {
            return 1;
        }
    }
    if (a->nimonId != b->nimonId) {
        if (a->nimonId <= b->nimonId) {
            return 0;
        } else {
            return 1;
        }
    }
}

int main() {
    // init();


    FILE * input = fopen("input.txt", "r");
    FILE * query = fopen("query.txt", "r");

    Mission missionsArr[MAX_MISSION];
    Mission Temp;
    int i = 0;

    while (i < MAX_MISSION && fscanf(input, "%d %d %d", &missionsArr[i].nimonId, &missionsArr[i].success, &missionsArr[i].missionValue) == 3) {
        if (missionsArr[i].nimonId == -1 && missionsArr[i].success == 0 && missionsArr[i].missionValue == 0) {
            break;
        }
        i++;
    }

    for (int j = 0; j < i - 1; j++) {
        for (int k = 0; k < i - j - 1; k++) {
            if (bubbleSortChecker(&missionsArr[k], &missionsArr[k + 1]) == 1) {
                Temp = missionsArr[k];
                missionsArr[k] = missionsArr[k+1];
                missionsArr[k+1] = Temp;
            }

        }
    }

    int count;
    
    fscanf(query, "%d", &count);

    int index;
    for (int c = 0; c < count; c++) {
        fscanf(query, "%d", &index);
        printf("%d %d\n", missionsArr[index -1].nimonId, missionsArr[index - 1].missionValue);        
    }
    
    fclose(input);
    fclose(query);
    /* Tulis kode dibawa ini */
    // TODO: baca file input.txt
    // TODO: tulis kode untuk algoritma utama
    // TODO: close file input.txt
    return 0;
}