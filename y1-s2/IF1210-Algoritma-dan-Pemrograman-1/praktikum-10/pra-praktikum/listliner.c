#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

Address newNode(ElType val) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        p->info = val;
        p->next = NULL;
    }
    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
    *l = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
    return (l == NULL);
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx) {
    int i = 0;
    while (i < idx) {
        l = l->next;
        i++;
    }
    return l->info;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val) {
    List current = *l;
    int i = 0;
    while (i < idx) {
        current = current->next;
        i++;
    }
    current->info = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val) {
    int i = 0;
    while (l != NULL) {
        if (l->info == val) return i;
        l = l->next;
        i++;
    }

    return IDX_UNDEF;
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
    Address newElmt = newNode(val);
    if (newElmt == NULL) return;   
    newElmt->next = *l;
    *l = newElmt;
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val) {
    Address newElmt = newNode(val);
    if (newElmt == NULL) return;
    
    if (*l == NULL) {
        *l = newElmt;
        return;
    }
    
    List current = *l;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newElmt;
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx) {
    Address newElmt = newNode(val);
    if (newElmt == NULL) return;
    
    if (idx == 0) {
        newElmt->next = *l;
        *l = newElmt;
        return;
    }
    
    List current = *l;
    for (int i = 0; i < idx - 1 && current != NULL; i++) {
        current = current->next;
    }

    newElmt->next = current->next;
    current->next = newElmt;
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
    List current = *l;
    *val = current->info;
    *l = current->next;
    free(current);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val) {
    List current = *l;

    if (current->next == NULL) {
        *val = current->info;
        *l = NULL;
        free(current);
        return;
    }

    while (current->next->next != NULL) {
        current = current->next;
    }

    *val = current->next->info;
    free(current->next);
    current->next = NULL;
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val) {
    List current = *l;
    Address prev;

    if (idx == 0) {
        deleteFirst(l, val);
        return;
    }

    for (int i = 0; i < idx; i++) {
        prev = current;
        current = current->next;
    }

    *val = current->info;
    prev->next = current->next;
    free(current);
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
    printf("[");
    while (l != NULL) {
        printf("%d", l->info);
        if (l->next != NULL) printf(",");
        l = l->next;
    }
    printf("]");
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l) {
    if (l == NULL) return 0;

    int len = 0;
    while (l != NULL) {
        l = l->next;
        len++;
    }

    return len;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    List newList = l1;
    Address lastNode = l1;
    
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    lastNode->next = l2;
    return newList;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */