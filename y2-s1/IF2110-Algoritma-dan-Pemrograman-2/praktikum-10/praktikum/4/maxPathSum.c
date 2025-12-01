#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

/* =======================================================
 * Fungsi Utama: maxPathSum
 * =======================================================
 *
 * Deskripsi:
 *   Mengembalikan nilai maksimum yang bisa dicapai oleh sebuah path
 *   pada binary tree.
 *
 * Spesifikasi:
 *   I.S.  : root terdefinisi (boleh NULL)
 *   F.S.  : Mengembalikan integer berupa maksimum path sum.
 *
 * Catatan:
 *   - Path boleh:
 *       * hanya satu node
 *       * melalui root atau tidak melalui root
 *       * melalui kiri → parent → kanan
 *       * setiap node hanya boleh dilewati satu kali.
 *       * dimulai dan diakhiri di node mana pun,
 *   - Setiap node ∈ [-10^5, 10^5]
 *   - Jumlah node n ∈ [1, 10^4]
 *
 * =======================================================
 */


/* =======================================================
 * ----------------------- CONTOH 1 -----------------------
 * =======================================================
 *
 *           (1)
 *          /   \
 *        (2)   (3)
 *
 * Semua path dan sum-nya:
 *  Path terbaik: 2 → 1 → 3 = 6
 *
 * Output: 6
 * =======================================================
 */


/* =======================================================
 * ----------------------- CONTOH 2 ------------------------
 * =======================================================
 *
 *                 (-10)
 *                 /    \
 *              (9)     (20)
 *                     /    \
 *                   (15)   (7)
 *
 * Path terbaik: 15 → 20 → 7 = 42
 *
 * Output: 42
 * --------------------------------------------------------
 */



int maxPathSum(BinTree root) {
    // int globalMax = -1000000000; // bila diperlukan

    /*
     * TODO:
     * - Implementasikan logika untuk mencari path sum maksimum.
     * - Boleh menambahkan fungsi rekursif helper bila diperlukan.
     * - Perhatikan kasus node bernilai negatif.
     */

    return 0;  /* Ubah nilai ini setelah implementasi */
}
