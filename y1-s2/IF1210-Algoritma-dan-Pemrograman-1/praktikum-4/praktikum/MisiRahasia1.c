#include <stdio.h>
#include <stdlib.h>
// #include "tester.h"

/* Tulis kode disini jika perlu */

int main() {
    // init();


    FILE * file = fopen("input.txt", "r");

    int nimon_id = 1, success, mission_value = 1;
    int last_id = 0, total_success = 0, total_value = 0;
    while ((nimon_id >= 1) && (nimon_id <= 1000) && (mission_value >= 0) && (mission_value <= 1000)) {
        fscanf(file, "%d %d %d", &nimon_id, &success, &mission_value); 
        if (nimon_id == -1) break;

        last_id++  ;

        if (success == 1) { 
            total_value += mission_value;
            total_success += 1;
        } 
   
    }

    fclose(file);
    printf("Total Misi: %d\n", last_id);
    printf("Misi Berhasil: %d\n", total_success);
    printf("Total Nilai Misi: %d\n", total_value);
    /* Tulis kode dibawa ini */
    // TODO: baca file input.txt
    // TODO: tulis kode untuk algoritma utama
    // TODO: close file input.txt
    return 0;
}