#include "listdin.h"
#include "stdlib.h"
#include <stdio.h>
#include <stdbool.h>

/* ********** KONSTRUKTOR ********** */
   /* Konstruktor : create list kosong  */
   void CreateListDin(ListDin *l, int capacity) {
        l->buffer = (ElType *) malloc(capacity * sizeof(ElType));
        l->capacity = capacity;
        l->nEff = 0;
   }
   /* I.S. l sembarang, capacity > 0 */
   /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
   
   void dealocateList(ListDin *l) {
        free(l->buffer);
        l->buffer = NULL;
        l->capacity = 0;
        l->nEff = 0;
   }
   /* I.S. l terdefinisi; */
   /* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
   
   /* ********** SELEKTOR (TAMBAHAN) ********** */
   /* *** Banyaknya elemen *** */
   int listLength(ListDin l) {
        return l.nEff;
   }
   /* Mengirimkan banyaknya elemen efektif list */
   /* Mengirimkan nol jika list l kosong */
   /* *** Daya tampung container *** */
   
   /* *** Selektor INDEKS *** */
   IdxType getFirstIdx(ListDin l) {
        return 0;
   }
   /* Prekondisi : List l tidak kosong */
   /* Mengirimkan indeks elemen l pertama */
   IdxType getLastIdx(ListDin l) {
        return l.nEff - 1;
   }
   /* Prekondisi : List l tidak kosong */
   /* Mengirimkan indeks elemen l terakhir */
   
   /* ********** Test Indeks yang valid ********** */
   boolean isIdxValid(ListDin l, IdxType i) {
        return (i >= 0 && i < l.capacity);
   }
   /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
   /* yaitu antara indeks yang terdefinisi utk container*/
   boolean isIdxEff(ListDin l, IdxType i) {
        return (i >= 0 && i < l.nEff);
   }
   /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
   /* yaitu antara 0..NEFF(l) */
   
   /* ********** TEST KOSONG/PENUH ********** */
   /* *** Test list kosong *** */
   boolean isEmpty(ListDin l) {
        return l.nEff == 0;
   }
   /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
   /* *** Test list penuh *** */
   boolean isFull(ListDin l) {
        return l.nEff == l.capacity;
   }
   /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
   
   /* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
   /* *** Mendefinisikan isi list dari pembacaan *** */
   void readList(ListDin *l) {
        int N;
        do {
            scanf("%d", &N);
        } while (N < 0 || N > l->capacity);

        if (N == 0) return;

        else {
            l->nEff = N;
            for (IdxType i = 0; i < l->nEff; i++) {
                scanf("%d", &l->buffer[i]);
            }
        }
   }
   /* I.S. l sembarang dan sudah dialokasikan sebelumnya */
   /* F.S. List l terdefinisi */
   /* Proses : membaca banyaknya elemen l dan mengisi nilainya */
   /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
   /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
   /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
   /* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
         0 satu per satu diakhiri enter */
   /*    Jika N = 0; hanya terbentuk l kosong */
   void printList(ListDin l) {
        printf("[");
        for (IdxType i = 0; i < l.nEff; i++) {
            printf("%d", l.buffer[i]);
            if (i < l.nEff - 1) printf(",");
        }
        printf("]");
   }
   /* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
      antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
      di tengah, atau di belakang, termasuk spasi dan enter */
   /* I.S. l boleh kosong */
   /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
   /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
   /* Jika list kosong : menulis [] */
   
   /* ********** OPERATOR ARITMATIKA ********** */
   /* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
   ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
        if (l1.nEff != l2.nEff) return;
        ListDin result;
        result.capacity = l1.capacity >= l2.capacity ? l1.capacity : l2.capacity;
        CreateListDin(&result, result.capacity);
        result.nEff - l1.nEff;

        for (int i = 0; i < NEFF(result); i++) {
            result.buffer[i] = (plus) ? l1.buffer[i] + l2.buffer[i] : l1.buffer[i] - l2.buffer[i];
        }
   }
   /* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
   /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
   /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
   
   /* ********** OPERATOR RELASIONAL ********** */
   /* *** Operasi pembandingan list : < =, > *** */
   boolean isListEqual(ListDin l1, ListDin l2) {
        if (NEFF(l1) != NEFF(l2)) return false;

        for (int i = 0; i < NEFF(l1); i++) {
            if (ELMT(l1, i) != ELMT(l2, i)) return false;
        }

        return true;
   }
   /* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
   
   /* ********** SEARCHING ********** */
   /* ***  Perhatian : list boleh kosong!! *** */
   IdxType indexOf(ListDin l, ElType val) {
        IdxType idx = IDX_UNDEF;
        for (int i = 0; i < l.nEff; i++) {
            if (ELMT(l, i) == val) {
                idx = i;
                break;
            }
        }
        return idx;
   }
   /* Search apakah ada elemen List l yang bernilai val */
   /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
   /* Jika tidak ada, mengirimkan IDX_UNDEF */
   /* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
   /* Skema Searching yang digunakan bebas */
   
   /* ********** NILAI EKSTREM ********** */
   void extremeValues(ListDin l, ElType *max, ElType *min) {
        if (l.nEff == 0) return;
        *max = ELMT(l, 0);
        *min = ELMT(l, 0);

        for (int i = 1; i < l.nEff; i++) {
            if (ELMT(l, i) > *max) *max = ELMT(l,i);
            if (ELMT(l, i) < *min) *min = ELMT(l,i);
        }
   }
   /* I.S. List l tidak kosong */
   /* F.S. max berisi nilai maksimum l;
           min berisi nilai minimum l */
   
   /* ********** OPERASI LAIN ********** */
   void copyList(ListDin lIn, ListDin *lOut) {
        if (lIn.nEff == 0) return;
        CreateListDin(lOut, lIn.capacity);
        for (int i = 0; i < lIn.nEff; i++) {
            lOut->buffer[i] = lIn.buffer[i];
        }
   }
   /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
   /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
   /* Proses : Menyalin isi lIn ke lOut */ 
   ElType sumList(ListDin l) {
        if (l.nEff == 0) return 0;
        int sum = 0;
        for (int i = 0; i < l.nEff; i++) {
            sum += l.buffer[i];
        }
        return sum;
   }
   /* Menghasilkan hasil penjumlahan semua elemen l */
   /* Jika l kosong menghasilkan 0 */
   int countVal(ListDin l, ElType val) {
        if (l.nEff == 0) return 0;
        int count = 0;
        for (int i = 0; i < l.nEff; i++) {
           if (l.buffer[i] == val) count++; 
        }
        return count;
}
   /* Menghasilkan berapa banyak kemunculan val di l */
   /* Jika l kosong menghasilkan 0 */
   
   /* ********** SORTING ********** */
   void sort(ListDin *l, boolean asc) {
        if (l->nEff == 0) return;
        int Temp;
        for (int i = 0; i < l->nEff; i++) {
            boolean swap;
            for (int j = 0; j < l->nEff - i - 1; j++) {
                swap = false;
                if (asc) {
                    if (l->buffer[i] > l->buffer[i + 1]) {
                        Temp = l->buffer[i];
                        l->buffer[i] = l->buffer[i + 1];
                        l->buffer[i + 1] = Temp;
                        swap = true;
                    }
                } else {
                    if (l->buffer[i] < l->buffer[i + 1]) {
                        Temp = l->buffer[i];
                        l->buffer[i] = l->buffer[i + 1];
                        l->buffer[i + 1] = Temp;
                        swap = true;
                    }
                }
                if (!swap) break;
            }
        }
   }
   /* I.S. l boleh kosong */
   /* F.S. Jika asc = true, l terurut membesar */
   /*      Jika asc = false, l terurut mengecil */
   /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
      algoritma bebas */
   
   /* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
   /* *** Menambahkan elemen terakhir *** */
   void insertLast(ListDin *l, ElType val) {
        if (l->nEff + 1 >= l->capacity) return;
        l->buffer[l->nEff] = val;
        l->nEff++;
   }
   /* Proses: Menambahkan val sebagai elemen terakhir list */
   /* I.S. List l boleh kosong, tetapi tidak penuh */
   /* F.S. val adalah elemen terakhir l yang baru */
   /* ********** MENGHAPUS ELEMEN ********** */
   void deleteLast(ListDin *l, ElType *val) {
        if (l->nEff == 0) return;

        *val = l->buffer[l->nEff--];

   }
   /* Proses : Menghapus elemen terakhir list */
   /* I.S. List tidak kosong */
   /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
   /*      Banyaknya elemen list berkurang satu */
   /*      List l mungkin menjadi kosong */
   
   /* ********* MENGUBAH UKURAN ARRAY ********* */
   void expandList(ListDin *l, int num) {
        l->capacity += num; 
        l->buffer = realloc(l->buffer, l->capacity * (sizeof(ElType)));
        //
    }
   /* Proses : Menambahkan capacity l sebanyak num */
   /* I.S. List sudah terdefinisi */
   /* F.S. Ukuran list bertambah sebanyak num */
   
   void shrinkList(ListDin *l, int num) {
        if (l->capacity <= num || l->nEff >= l->capacity - num) return;
        l->capacity -= num;
        l->buffer = realloc(l->buffer, l->capacity * (sizeof(ElType)));

   }
   /* Proses : Mengurangi capacity sebanyak num */
   /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
   /* F.S. Ukuran list berkurang sebanyak num. */
   
   void compressList(ListDin *l) {
        if (isEmpty(*l)) return;
        l->capacity = l->nEff;
        l->buffer = realloc(l->buffer, l->capacity * (sizeof(ElType)));
   }
   /* Proses : Mengubah capacity sehingga nEff = capacity */
   /* I.S. List tidak kosong */
   /* F.S. Ukuran nEff = capacity */
   
