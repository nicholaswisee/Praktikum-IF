#include "liststatik.h"
#include <stdio.h>
#include "Boolean.h"

#define true 1
#define false 0

void CreateListStatik(ListStatik *l) {
    for (int i = 0; i < CAPACITY; i++) {
        ELMT(*l, i) = MARK;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l) {
    int len = 0;
    for (int i = 0; i < CAPACITY; i++) {
        if (ELMT(l, i) == MARK) return len;
        len++;
    }
    return len;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l) {
    return 0;                       
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListStatik l) {
    if (isEmpty(l)) return IDX_UNDEF;
    for (int i = CAPACITY - 1; i >= IDX_MIN; i--) {
        if (ELMT(l, i) != MARK) return i;
    }
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i) {
    return (i >= getFirstIdx(l) && i < CAPACITY) ? true : false;
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListStatik l, IdxType i) {
    return (i >= 0 && i < listLength(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l) {
    return (ELMT(l, 0) == MARK);
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListStatik l) {
    return (listLength(l) == CAPACITY) ? true : false;
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l) {
    IdxType n;
    CreateListStatik(l);

    do {
        scanf("%d", &n);
    } while (n < 0 || n > CAPACITY);

    if (n == 0) return;
    for (IdxType i = 0; i < n; i++) {
        scanf("%d", &l->contents[i]);
    }
    l->contents[n] = MARK;
}
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void printList(ListStatik l) {
    printf("[");
    for (IdxType i = 0; i < listLength(l); i++) {
        printf("%d", ELMT(l,i));
        if (i < listLength(l) - 1) printf(",");
    }
    printf("]");
    printf("\n");
}
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
    ListStatik result;
    ElType res;
    CreateListStatik(&result);
    for (int i = getFirstIdx(l1); i <= getLastIdx(l2); i++) {
        if (plus) res = l1.contents[i] + l2.contents[i];
        else res = l1.contents[i] - l2.contents[i];
        if (res == MARK) {
            // Optional: set result to a safe placeholder or raise error
            res = MARK + 1; // E.g., if MARK is -9999, use -9998
        }
        result.contents[i] = res;
    }
    return result;
}
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2) {
    if (listLength(l1) != listLength(l2)) return false;

    for (int i = getFirstIdx(l1); i <= getLastIdx(l1); i++) {
        if (l1.contents[i] != l2.contents[i]) return false;
    }
    
    return true;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val) {
    for (int i = 0; i < listLength(l); i++) {
        if (ELMT(l, i) == val) return i;
    }
    return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min) {
    ElType maxVal = l.contents[0];
    ElType minVal = l.contents[0];

    for (int i = 0; i < listLength(l); i++) {
        if (l.contents[i] > maxVal) maxVal = l.contents[i];
        if (l.contents[i] < minVal) minVal = l.contents[i];
    }

    *max = maxVal;
    *min = minVal;
}
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val) {
    if (isFull(*l)) return;
    for (int i = getLastIdx(*l); i >= 0; i--) {
        l->contents[i + 1] = l->contents[i];
    }
    l->contents[0] = val;
}
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, ElType val, IdxType idx) {
    if (isFull(*l)) return;
    if (isEmpty(*l)) { // Jika list kosong, tambahkan langsung di indeks 0
        l->contents[0] = val;
        return;
    }
    if (!isIdxValid(*l, idx)) return;
    for (int i = getLastIdx(*l); i >= idx; i--) {
        l->contents[i + 1] = l->contents[i];
    }
    l->contents[idx] = val;
}
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, ElType val) {
    if (isFull(*l)) return;
    l->contents[listLength(*l)] = val; 
    l->contents[listLength(*l) + 1] = MARK; 
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val) {
    if (isEmpty(*l)) return;
    IdxType lastIdx = getLastIdx(*l);
    if (val != NULL) {
        *val = l->contents[0];
    }
    for (int i = 0; i < lastIdx; i++) {
        l->contents[i] = l->contents[i + 1];
    }
    l->contents[lastIdx] = MARK;
}
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
    if (!isIdxValid(*l, idx)) return;
    if (isEmpty(*l)) return;

    IdxType lastIdx = getLastIdx(*l);
    *val = l->contents[idx];
    for (int i = idx; i < lastIdx; i++) {
        l->contents[i] = l->contents[i + 1];
    }
    l->contents[lastIdx] = MARK;
}
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val) {
    if (isEmpty(*l)) return;
    if (val != NULL) *val = l->contents[getLastIdx(*l)];
    l->contents[getLastIdx(*l)] = MARK;
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc) {
    if (isEmpty(*l)) return;
    IdxType lastIndex = getLastIdx(*l);
    ElType Temp;
    for (int i = 0; i < lastIndex; i++) {
        for (int j = 0; j < lastIndex - i; j++) {
            if (asc) {
                if (l->contents[j] > l->contents[j + 1]) {
                    Temp = l->contents[j];
                    l->contents[j] = l->contents[j + 1];
                    l->contents[j + 1] = Temp;
                }
            } else {
                if (l->contents[j] < l->contents[j + 1]) {
                    Temp = l->contents[j];
                    l->contents[j] = l->contents[j + 1];
                    l->contents[j + 1] = Temp;
                }
            }
        }
    }
} 
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */