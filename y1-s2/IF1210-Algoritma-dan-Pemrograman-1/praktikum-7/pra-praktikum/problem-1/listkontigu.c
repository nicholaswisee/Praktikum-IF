#include "listkontigu.h"
#include "Boolean.h"

#define boolean unsigned char
#define true 1
#define false 0

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong */
void CreateList(ListKontigu *l) {
    for (int i = 0; i < CAPACITY; i++) {
        l->contents[i] = MARK;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk ListKontigu l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen fisik ListKontigu l dengan MARK */

/* ********** SELEKTOR  ********** */

/* *** Pencari Indeks Fisik Batas Efektif *** */
int firstIdx(ListKontigu l){
    for (int i = 0; i < CAPACITY; i++) {
        if (l.contents[i] != MARK) return i;
    }
    return IDX_UNDEF;
}
/* Prekondisi : List l boleh kosong */
/* Mengirimkan indeks fisik elemen valid pertama dalam list l, */
/* atau IDX_UNDEF jika l kosong */

int lastIdx(ListKontigu l) {
    for (int i = CAPACITY - 1; i >= 0; i--) {
        if (l.contents[i] != MARK) return i;
    }
    return IDX_UNDEF;
}
/* Prekondisi : List l boleh kosong */
/* Mengirimkan indeks fisik elemen valid terakhir dalam list l, */
/* atau IDX_UNDEF jika l kosong */

/* *** Banyaknya elemen *** */
int listLength(ListKontigu l) {
    if (firstIdx(l) == IDX_UNDEF || lastIdx(l) == IDX_UNDEF) return 0;
    
    return lastIdx(l) - firstIdx(l) + 1;
}
/* Mengirimkan banyaknya elemen efektif ListKontigu */
/* Mengirimkan nol jika List kosong */

ElType getElmt(ListKontigu l, int i) {
    return ELMT(l , firstIdx(l) + i);
}
/* Prekondisi : List l tidak kosong, i adalah indeks logis yang valid (0..listLength(l)-1) */
/* Mengirimkan elemen List yang ke-i (indeks logis) */

/* *** Mengubah elemen berdasarkan indeks logis *** */
void setElmt(ListKontigu *l, int i, ElType val) {
    if (isEmpty(*l) || i < 0 || i >= listLength(*l)) return;
    l->contents[firstIdx(*l) + i] = val;
}
/* I.S. List l tidak kosong, i adalah indeks logis yang valid (0..listLength(l)-1) */
/* F.S. Elemen List yang ke-i secara logis bernilai val */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(int i) {
    return (i >= IDX_MIN && i <= CAPACITY - 1);
}
/* Mengirimkan true jika i adalah indeks fisik yang valid untuk array  */
/* yaitu antara IDX_MIN dan CAPACITY-1 */

boolean isIdxEff(ListKontigu l, int i) {
    if (isEmpty(l)) return false;
    return (i >= firstIdx(l) && i <= lastIdx(l));
}
/* Mengirimkan true jika i adalah indeks fisik yang efektif (valid secara fisik */
/* dan merupakan bagian dari elemen list yang valid). */
/* yaitu i >= firstIdx(l) dan i <= lastIdx(l). */
/* Mengembalikan false jika l kosong. */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListKontigu l) {
    for (int i = 0; i < CAPACITY; i++) {
        if (l.contents[i] != MARK) return false;
    }
    return true;
}
/* Mengirimkan true jika List l kosong (tidak memiliki elemen efektif) */


/* *** Test List penuh *** */
boolean isFull(ListKontigu l) {
    for (int i = 0; i < CAPACITY; i++) {
        if (l.contents[i] == MARK) return false;
    }
    return true;
}
/* Mengirimkan true jika List l penuh (jumlah elemen efektif == CAPACITY) */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListKontigu *l) {
    int N;
    do {
        scanf("%d", &N);
    } while (N < 0 || N > CAPACITY);

    CreateList(l);
    for (int i = 0; i < N; i++) {
        scanf("%d", &l->contents[i]);
    }
}
/* I.S. l sembarang */
/* F.S. ListKontigu l terdefinisi  */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya secara kontigu dalam list, seluruh elemen fisik lain di luar blok efektif di-set MARK.  */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */

void printList(ListKontigu l) {
    printf("[");
    if (isEmpty(l)) printf("]");
    else {
        for (int i = firstIdx(l); i <= lastIdx(l); i++) {
            printf("%d", l.contents[i]);
            if (i != lastIdx(l)) printf(",");
        }
        printf("]");
    }
}
/* Proses : Menuliskan isi list efektif dengan traversal. */
/* List ditulis di antara kurung siku; antara dua elemen dipisahkan dengan separator "koma". */
/* Tanpa tambahan karakter di depan, di tengah, atau di belakang. */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] (e adalah elemen pada indeks logis) */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListKontigu l1, ListKontigu l2) {
    if (firstIdx(l1) != firstIdx(l2) || lastIdx(l1) != lastIdx(l2) || listLength(l1) != listLength(l2)) return false;
    if (isEmpty(l1) && isEmpty(l2)) return true;

    for (int i = firstIdx(l1); i <= lastIdx(l1); i++) {
        if (l1.contents[i] != l2.contents[i]) return false;
    }
    return true;
}
/* Mengirimkan true jika l1 sama dengan l2 */
/* yaitu jika panjangnya sama dan elemen pada indeks logis yang sama juga sama */

/* ********** SEARCHING ********** */
/* *** Mencari elemen berdasarkan nilai *** */
int indexOf(ListKontigu l, ElType val) {
    if (isEmpty(l)) return IDX_UNDEF;
    
    for (int i = firstIdx(l); i <= lastIdx(l); i++)  {
        if (l.contents[i] == val) return (i - firstIdx(l));
    }

    return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks LOGIS (0..length-1) elemen pertama yang bernilai val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */


/* ********** OPERASI LAIN ********** */
void copyList(ListKontigu lIn, ListKontigu *lOut) {
    CreateList(lOut);

    int firstId = firstIdx(lIn);
    int lastId = lastIdx(lIn);
    int j = 0;

    for (int i = firstId; i <= lastId; i++) {
        lOut->contents[j] = lIn.contents[i];
        j++;
    }

}
/* I.S. lIn terdefinisi, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (elemen efektif disalin, */
/*      dimulai dari indeks fisik 0 di lOut, sisanya MARK). */


void shiftBlock(ListKontigu *l, int startPhys, int endPhys, int delta) {
    if (delta > 0) {
        for (int i = endPhys; i >= startPhys; i--) {
            l->contents[i + delta] = l->contents[i];
            l->contents[i] = MARK;
        } 
    } else {
        for (int i = startPhys; i <= endPhys; i++) {
            l->contents[i + delta] = l->contents[i];
            l->contents[i] = MARK;
        } 
    }
}
/* I.S. List l terdefinisi, ada cukup ruang MARK di arah pergeseran */
/* F.S. Elemen fisik dari startPhys hingga endPhys digeser ke kanan (delta > 0) */
/* atau ke kiri (delta < 0), elemen yang kosong dijadikan MARK. */

/* ********** PENAMBAHAN ELEMEN ********** */
/* *** Menambahkan elemen berdasarkan nilai *** */
void insertFirst(ListKontigu *l, ElType val) {
    if (isFull(*l)) return;

    int firstId = firstIdx(*l);
    int lastId = lastIdx(*l);

    if (isEmpty(*l)) l->contents[0] = val;
    else if (isIdxValid(firstIdx(*l) - 1)) l->contents[firstIdx(*l) - 1] = val;
    else {
        for (int i = lastId; i >= firstId; i--) {
            l->contents[i + 1] = l->contents[i];
        }
        l->contents[0] = val;
    }
}
/* Menambahkan val sebagai elemen pertama List l (indeks logis 0) */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val menjadi elemen pertama l, list mungkin bergeser secara fisik. */
/* Proses:
   1. Jika list kosong, tempatkan val di indeks fisik 0.
   2. Jika tidak kosong dan ada ruang di indeks fisik firstIdx(l)-1, tempatkan val di sana.
   3. Jika tidak kosong dan tidak ada ruang di kiri (firstIdx=0) tapi ada ruang di kanan,
      geser semua elemen efektif [firstIdx..lastIdx] ke kanan satu posisi,
      lalu tempatkan val di firstIdx fisik yang lama. */

void insertLast(ListKontigu *l, ElType val) {
    int firstId = firstIdx(*l);
    int lastId = lastIdx(*l);

    if (isFull(*l)) return;
    if (isEmpty(*l)) l->contents[0] = val;
    else if (isIdxValid(lastId + 1)) l->contents[lastId + 1] = val;
    else {
        for (int i = firstId; i <= lastId; i++) {
            l->contents[i - 1] = l->contents[i];
        }
        l->contents[CAPACITY - 1] = val;
    }
}
/* Menambahkan val sebagai elemen terakhir List l (indeks logis length) */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val menjadi elemen terakhir l, list mungkin bergeser secara fisik. */
/* Proses: Mirip insertFirst, tapi di ujung kanan (lastIdx).
   1. Jika list kosong, tempatkan val di indeks fisik 0.
   2. Jika tidak kosong dan ada ruang di indeks fisik lastIdx(l)+1, tempatkan val di sana.
   3. Jika tidak kosong dan tidak ada ruang di kanan  tapi ada ruang di kiri,
      geser semua elemen efektif [firstIdx..lastIdx] ke kiri satu posisi,
      lalu tempatkan val di lastIdx fisik yang lama. */

void insertAt(ListKontigu *l, ElType val, int i) {
    int firstId = firstIdx(*l);
    int lastId = lastIdx(*l);

    if (isEmpty(*l) && i == 0) l->contents[0] = val;
    else {
        int physTarget = firstId + i;
        if (lastId + 1 < CAPACITY) {
            for (int j = lastId; j >= physTarget; j--) {
                l->contents[j + 1] = l->contents[j]; 
            }
        } else {
            for (int j = firstId; j <= physTarget; j++) {
                l->contents[j - 1] = l->contents[j];
            }
        }
        l->contents[physTarget] = val;
    }
}
/* Menambahkan val sebagai elemen pada indeks logis ke-i */
/* I.S. List l tidak penuh, mungkin kosong. */
/*      Jika l tidak kosong, i adalah indeks logis yang valid untuk penambahan (0..listLength(l)). */
/* F.S. val disisipkan pada indeks logis ke-i, elemen setelahnya digeser. List mungkin bergeser secara fisik. */
/* Proses:
   1. Jika list kosong (i harus 0), sama seperti insertFirst/Last.
   2. Jika 0 < i < listLength(l):
      a. Tentukan indeks fisik target: physTarget = firstIdx(l) + i.
      b. Cek ruang: Prioritaskan menggeser ke kanan jika ada ruang setelah lastIdx.
         Geser elemen dari physTarget hingga lastIdx ke kanan satu posisi.
      c. Jika tidak ada ruang kanan, coba geser ke kiri jika ada ruang sebelum firstIdx.
         Geser elemen dari firstIdx hingga physTarget-1 ke kiri satu posisi.
         physTarget sekarang menjadi physTarget-1.
      d. Tempatkan val di ELMT(*l, physTarget). */


/* ********** PENGHAPUSAN ELEMEN ********** */
void deleteFirst(ListKontigu *l, ElType *val) {
    if (isEmpty(*l)) return;

    *val = l->contents[firstIdx(*l)];
    l->contents[firstIdx(*l)] = MARK;
}
/* Menghapus elemen pertama List l (indeks logis 0) */
/* I.S. List l tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum dihapus. */
/*      Elemen pertama fisik (di firstIdx) di-set menjadi MARK. */

void deleteLast(ListKontigu *l, ElType *val) {
    if (isEmpty(*l)) return;

    *val = l->contents[lastIdx(*l)];
    l->contents[lastIdx(*l)] = MARK;
}
/* Menghapus elemen terakhir list (indeks logis length-1) */
/* I.S. List l tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum dihapus. */
/*      Elemen terakhir fisik (di lastIdx) di-set menjadi MARK. */

void deleteAt(ListKontigu *l, int i, ElType *val) {
    if (isEmpty(*l)) return;
    if (isFull(*l)) l->contents[lastIdx(*l)] = MARK;
    
    int physTarget = firstIdx(*l) + i;
    int lastId = lastIdx(*l);

    *val = l->contents[physTarget];

    for (int j = physTarget; j <= lastId; j++) {
        l->contents[j] = l->contents[j + 1];
    } 

    l->contents[lastId] = MARK;
}
/* Menghapus elemen pada indeks logis ke-i */
/* I.S. List l tidak kosong, i adalah indeks logis yang valid (0..listLength(l)-1) */
/* F.S. val adalah nilai elemen pada indeks logis i sebelum dihapus. */
/*      Elemen pada indeks logis i dihapus dari list, elemen setelahnya digeser ke kiri */
/*      secara fisik untuk menjaga kontiguitas blok. */
/* 
    Jika 0 < i < listLength(l)-1:
      a. Tentukan indeks fisik target: physTarget = firstIdx(l) + i.
      b. Simpan ELMT(l, physTarget) ke val.
      c. Geser elemen dari physTarget+1 hingga lastIdx(l) ke kiri satu posisi.
      d. Set ELMT(*l, lastIdx(l)) = MARK (posisi fisik terakhir yang lama). */


/* ********** OPERASI PENGGABUNGAN ********** */
void concat(ListKontigu l1, ListKontigu l2, ListKontigu *l3) {
        if (isEmpty(l1)) {
            copyList(l2, l3);
        } else {
            copyList(l1, l3);
            if (isEmpty(l2)) return;    
            int firstL2 = firstIdx(l2);
            int start = lastIdx(*l3);
            
            for (int i = start + 1; i < CAPACITY; i++) {
                l3->contents[i] = l2.contents[firstL2++];
            }
        }
}
/* I.S. l1 dan l2 terdefinisi, boleh kosong. l3 sembarang. */
/* F.S. l3 adalah hasil penggabungan elemen efektif l1 dan l2. */
/*      Elemen l1 disalin terlebih dahulu, diikuti elemen l2. */
/*      Hasilnya ditempatkan di l3 mulai dari indeks fisik 0. */
/*      Jika total elemen > CAPACITY, hanya elemen yang muat yang disalin. */