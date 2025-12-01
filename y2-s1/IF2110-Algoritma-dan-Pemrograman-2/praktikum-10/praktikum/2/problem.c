/* =======================================================
 * File: problem.c
 * Deskripsi:
 *   Implementasi fungsi untuk menghitung jumlah "good nodes"
 *   pada sebuah binary tree.
 *
 *   Sebuah node X disebut "good" jika pada path dari root ke X,
 *   tidak ada node dengan nilai lebih besar dari X.
 *
 * ======================================================= */

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"


/* =======================================================
 * Fungsi Utama: countGoodNodes
 * =======================================================
 *
 * Deskripsi:
 *   Menghitung jumlah "good nodes" pada sebuah binary tree.
 *   Sebuah node X adalah "good" jika dalam path dari root ke X,
 *   tidak ada node dengan nilai yang lebih besar dari X.
 *
 * Spesifikasi:
 *   I.S.  : p terdefinisi (mungkin NULL)
 *   F.S.  : Mengembalikan jumlah good nodes (integer >= 0)
 *
 * Catatan:
 *   - Jumlah node n ∈ [1, 10^4].
 *   - Nilai node ∈ [-10^4, 10^4].
 *   - Root selalu dianggap sebagai good node.
 *   - Gunakan DFS dengan tracking nilai maksimum pada path.
 */

/* =======================================================
 * ----------------------- CONTOH 1 ------------------------
 * =========================================================
 * Misal pohon terbentuk:
 *
 *           (3)
 *          /   \
 *        (1)   (4)
 *       /     /  \
 *     (3)  (1)  (5)
 *
 * Path dan analisis:
 * - Node 3 (root): good (selalu good)
 * - Node 1 (kiri root): tidak good (3 > 1 pada path)
 * - Node 4 (kanan root): good (4 > 3)
 * - Node 3 (kiri-kiri): good (3 >= 3 pada path)
 * - Node 1 (kanan-kiri): tidak good (4 > 1 pada path)
 * - Node 5 (kanan-kanan): good (5 > 4)
 *
 * Good nodes: 3, 3, 4, 5
 * Hasil: 4
 * Output: 4
 * ======================================================= */

/*
 * ----------------------- CONTOH 2 ------------------------
 * Misal pohon 2:
 *
 *           (3)
 *          /
 *        (3)
 *       /  \
 *     (4)  (2)
 *
 * Path dan analisis:
 * - Node 3 (root): good
 * - Node 3 (kiri): good (3 >= 3)
 * - Node 4 (kiri-kiri): good (4 > 3)
 * - Node 2 (kiri-kanan): tidak good (3 > 2)
 *
 * Good nodes: 3, 3, 4
 * Hasil: 3
 * Output: 3
 * --------------------------------------------------------
 */

/* Fungsi helper untuk DFS dengan tracking maksimum */
int countGoodNodesHelper(BinTree p, int maxSoFar) {
    /* ====== TODO: Implementasi di bawah ini ====== */
    /* Hint:
     * 1. Base case: jika node NULL, return 0
     * 2. Cek apakah node saat ini "good" (ROOT(p) >= maxSoFar)
     * 3. Update maxSoFar untuk rekursi ke anak
     * 4. Rekursi ke LEFT(p) dan RIGHT(p) dengan maxSoFar yang sudah diupdate
     * 5. Return jumlah total good nodes
     */
    
    if (p == NULL) return 0;

    if (ROOT(p) >= maxSoFar) {
        return 1 + countGoodNodesHelper(LEFT(p), ROOT(p)) + countGoodNodesHelper(RIGHT(p), ROOT(p));
    } else {
        return countGoodNodesHelper(LEFT(p), maxSoFar) + countGoodNodesHelper(RIGHT(p), maxSoFar);
    }
}

int countGoodNodes(BinTree p) {
    /* ====== TODO: Implementasi di bawah ini ====== */
    /* Hint: 
     * 1. Handle edge case jika p == NULL
     * 2. Panggil fungsi helper dengan parameter awal yang sesuai
     */
    
    if (p == NULL) return 0;

    return countGoodNodesHelper(p, -10001);
}
