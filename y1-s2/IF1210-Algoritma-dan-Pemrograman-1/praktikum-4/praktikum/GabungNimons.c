#include <stdio.h>
// #include "tester.h" 

int main () {
    // init(); // Comment this when developing in local
    FILE * file_a = fopen("file_a.txt", "r");
    FILE * file_b = fopen("file_b.txt", "r");

    int id_a, pisang_a, id_b, pisang_b;
    int id_arr[1000] = {0};
    int pisang_arr[1000] = {0};
    int cond = 1;

    int largest_id = 0;
    int n = 1;
    while (cond) {

        fscanf(file_a, "%d %d", &id_a, &pisang_a);
        
        if (id_a == -1) break;

        id_arr[id_a] = id_a;        
        pisang_arr[id_a] = pisang_a;
        n++;

    }
    fclose(file_a);

    cond = 1;
    while (cond) {
        fscanf(file_b, "%d %d", &id_b, &pisang_b);
        
        if (id_b == -1) break;

        id_arr[id_b] = id_b;        
        pisang_arr[id_b] = pisang_b;
        n++;
    }
    
    fclose(file_b);

    id_arr[n] = -1;
    for (int i = 1; i < 1000; i++) {
        if (pisang_arr[i] == 0) continue;
        if (id_arr[i] == -1) break;

        printf("%d %d\n", id_arr[i], pisang_arr[i]);
    }

    /* Write your code here */
    return 0;
}