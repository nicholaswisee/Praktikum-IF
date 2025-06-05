#include "moveon.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Fungsi : removeAll
 * -------------------
 * Menghapus semua elemen dalam list yang memiliki nilai info sama dengan 'val'.
 *
 * Parameter:
 *  - l   : pointer ke list yang akan dimodifikasi
 *  - val : nilai elemen yang ingin dihapus dari list
 *
 * Deskripsi:
 *  - Fungsi ini melakukan traversal pada list l dan menghapus semua node
 *    yang memiliki nilai INFO(node) == val.
 *  - Penghapusan dilakukan dengan benar, termasuk menangani kasus:
 *      - Node yang dihapus berada di awal list
 *      - Node yang dihapus berada di tengah list
 *      - Node yang dihapus berada di akhir list
 *  - Setelah node dihapus, memori dari node tersebut harus di-dealokasi (menggunakan free).
 *
 * Aturan:
 *  - Tidak boleh menggunakan array tambahan, struktur data lain, atau rekursi.
 *  - Hanya boleh menggunakan operasi pointer dan fungsi dari ADT listlinier.h
 *  - Tidak memodifikasi nilai dari node lain, hanya menghapus node yang sesuai.
 *
 * Contoh:
 *  - Jika list l = [1, 2, 2, 3, 2, 4] dan val = 2,
 *    maka setelah removeAll(&l, 2), list menjadi [1, 3, 4]
 */
void removeAll(List *l, ElType val) {
    int idx = 0;
    ElType temp;
    Address current = *l;

    while (current != NULL) {
        if (current->info == val) {
            current = current->next;
            deleteAt(l, idx, &temp);
        }
        
        if (current->info != val) {
            current = current->next;
            idx++;
        }
    }
    
    displayList(*l);
    printf("\n");
    // Node *temp = *l;
    // Node *temp2;
    // ElType buang;
    // int awal = 1;
    // while(temp != NULL){
    //     if (awal && temp->info == val){
    //         deleteFirst(l, &buang);
    //         awal = 0;
    //     }
    //     else if (temp->next != NULL && temp->next->info == val){
    //         temp2 = temp->next;
    //         temp->next = temp->next->next;
    //         free(temp2);
    //     }
    // }
    // displayList(l);
}
