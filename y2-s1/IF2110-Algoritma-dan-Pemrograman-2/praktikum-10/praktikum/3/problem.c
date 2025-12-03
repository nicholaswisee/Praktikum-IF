/* =======================================================
 * File: problem.c
 * Deskripsi:
 *   Implementasi fungsi untuk mencari level pada binary tree
 *   yang memiliki jumlah nilai node (sum) terbesar.
 *
 *   Level dari root adalah 1, level anak-anaknya adalah 2, dan seterusnya.
 *   Jika ada lebih dari satu level dengan sum maksimal yang sama,
 *   kembalikan level terkecil (paling atas).
 *
 * ======================================================= */

 #include <stdio.h>
 #include <stdlib.h>
 #include "bintree.h"   /* Asumsikan ADT bintree sudah disediakan */

 /* =======================================================
  * Fungsi Utama: levelMaxSum
  * =======================================================
  *
  * Deskripsi:
  *   Mengembalikan level dengan jumlah nilai node (sum) terbesar
  *   dari sebuah binary tree.
  *
  * Spesifikasi:
  *   I.S.  : root terdefinisi (mungkin NULL)
  *   F.S.  : Mengembalikan nilai level (integer >= 1)
  *           dengan sum tertinggi.

  * Catatan:
  *   - Jumlah node n ∈ [1, 10^4].
  *   - Nilai node ∈ [-10^5, 10^5].
  *   - Jika ada lebih dari satu level dengan sum maksimal yang sama,
  *     kembalikan level terkecil (paling atas).
  */

  /* =======================================================
 * ----------------------- CONTOH 1 ------------------------
 * =========================================================
 * Misal pohon terbentuk:
 *
 *           (1)
 *          /   \
 *        (7)   (0)
 *       /  \
 *     (7)  (-8)
 *
 * Level 1 → sum = 1
 * Level 2 → sum = 7 + 0 = 7
 * Level 3 → sum = 7 + (-8) = -1
 *
 * Hasil: level 2 (7 adalah sum tertinggi)
 * Output : 2
 * ======================================================= */

 /*
 * ----------------------- CONTOH 2 ------------------------
 * Misal pohon 2:
 *
 *              (989)
 *                 \
 *                (10250)
 *               /      \
 *           (98693)   (-89388)
 *                      \
 *                      (-32127)
 *
 * Level 1 → sum = 989
 * Level 2 → sum = 10250
 * Level 3 → sum = 98693 + (-89388) = 929305
 * Level 4 → sum = -32127
 *
 * Jadi level dengan jumlah terbesar adalah level 2 (sum = 10250)
 * Output  : 2
 * --------------------------------------------------------
 */
 
 int levelMaxSum(struct treeNode* root) {
    if (root == NULL) {
        return 0;
    }


    struct treeNode* queue[10005];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    int currentLevel = 1;
    int maxLevel = 1;
    
    int maxSum = -9999999; 

    while (front < rear) {
        int levelSize = rear - front; // Jumlah node pada level saat ini
        long long currentLevelSum = 0;

        // Proses semua node pada level ini
        for (int i = 0; i < levelSize; i++) {
            struct treeNode* node = queue[front++]; // Dequeue

            currentLevelSum += node->info;

            if (node->left != NULL) {
                queue[rear++] = node->left;
            }
            if (node->right != NULL) {
                queue[rear++] = node->right;
            }
        }
		// Cek apakah sum level saat ini adalah yang terbesar
        if (currentLevelSum > maxSum) {
            maxSum = currentLevelSum;
            maxLevel = currentLevel;
        }

        currentLevel++;
    }

    return maxLevel;
} 
 