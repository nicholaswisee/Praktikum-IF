#include <stdio.h>
#include "graph.h"

/* 
 * Problem: Temukan Master Nimon
 * 
 * Di sebuah lab, terdapat n nimon yang diberi label dari 1 sampai n.
 * Ada rumor bahwa salah satu dari nimon ini sebenarnya adalah Master Nimon yang menyamar.
 * 
 * Jika Master Nimon ada, maka:
 * 1. Master Nimon tidak mengikuti siapapun (tidak punya atasan).
 * 2. Semua nimon (kecuali Master Nimon) mengikuti Master Nimon.
 * 3. Hanya ada tepat satu nimon yang memenuhi properti 1 dan 2.
 * 
 * Diberikan array follow dimana follow [i] = [a, b] merepresentasikan bahwa 
 * nimon a mengikuti nimon b.
 * 
 * Return label dari Master Nimon jika dia ada dan bisa diidentifikasi, 
 * atau return -1 jika tidak.
 * 
 * Test Cases:
 * 
 * Test Case 1:
 * Input: n = 3, follow = [[1,2],[2,3]]
 * Output: -1
 * Penjelasan: Nimon 1 mengikuti 2, nimon 2 mengikuti 3. Tidak ada nimon yang 
 * diikuti oleh semua nimon lainnya.
 * 
 * Test Case 2:
 * Input: n = 3, follow = [[1,3],[2,3]]
 * Output: 3
 * Penjelasan: Nimon 1 dan 2 mengikuti nimon 3. Nimon 3 tidak mengikuti siapapun.
 * Nimon 3 memenuhi semua kriteria Master Nimon.
 * 
 * Test Case 3:
 * Input: n = 3, follow = [[1,3],[2,3],[3,1]]
 * Output: -1
 * Penjelasan: Nimon 3 mengikuti nimon 1, sehingga nimon 3 tidak bisa menjadi 
 * Master Nimon (melanggar kriteria 1).
 * 
 */

/* 
 * @param n: jumlah total nimon dalam lab (1 sampai n)
 * @param follow: array 2D yang berisi relasi follow, dimana follow[i][0] mengikuti follow[i][1]
 * @param followCount: jumlah relasi follow yang ada dalam array follow
 * @return: label Master Nimon jika ditemukan, atau -1 jika tidak ada
 */
int findMaster(int n, int follow[][2], int followCount) {
    Graph g;
    AdrNode p; // temp variable
    for (int i = 1; i <= n; i++) {
        insertNode(&g, i, &p);
    }

    // insert edge
    int prec, succ;
    for (int j = 0; j < followCount; j++) {
        prec = follow[j][0];
        succ = follow[j][1];

        insertEdge(&g, prec, succ);
    }

    int master = 0;
    AdrNode check = g.first;
    while (check != NULL) {
        if (check->nPred == n - 1 && check->trail == NULL && master == 0) {
            master = check->id;
        } else if (check->nPred == n - 1 && check->trail == NULL && master != 0) {
            return -1;
        }
        
        check = check->next;
    }

    return master == 0 ? -1 : master;

    // return 1;
}

int main() {
    int n = 3;
    int followCount = 2;

    int follow[2][2] = {{1,2}, {2,3}};

    int res = findMaster(n, follow, 2);
    printf("%d", res);

    return 0;
}