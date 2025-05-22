#include "stack.h"
#include <stdio.h>
#include "boolean.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S) {
    S->TOP = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S) {
    return (S.TOP == Nil);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S) {
    return (S.TOP == MaxEl - 1);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X) {
    if (IsFull(*S)) return;
    if (IsEmpty(*S)) {
        S->T[0] = X;
        S->TOP = 0;
    } else {
        S->TOP += 1;
        S->T[S->TOP] = X;
    }
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X) {
    if (IsEmpty(*S)) return;

    *X = S->T[S->TOP];
    if (S->TOP == 0) {
        S->TOP = Nil;
    }
    else {
        S->TOP -= 1;
    }

}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

