/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
memori list dinamik */

// #ifndef LISTDIN_H
// #define LISTDIN_H

#include "Boolean.h"
#include <stdio.h> 
#include "listdin.h"
#include <stdbool.h> 
#include <stdlib.h> 
// /*  Kamus Umum */
// #define IDX_MIN 0
// // /* Indeks minimum list */
// #define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
// typedef int ElType; /* type elemen list */
// typedef int IdxType;
// typedef struct
// {
//     ElType *buffer; /* memori tempat penyimpan elemen (container) */
//     int nEff;       /* >=0, banyaknya elemen efektif */
//     int capacity;   /* ukuran elemen */
// } ListDin;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
    l.nEff      untuk mengetahui banyaknya elemen
    l.buffer    untuk mengakses seluruh nilai elemen list
    l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
    list kosong: l.nEff = 0
    Definisi elemen pertama : l.buffer[i] dengan i=0
    Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
// #define NEFF(l) (l).nEff
// #define BUFFER(l) (l).buffer
// #define ELMT(l, i) (l).buffer[i]
// #define CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
    l->buffer = (ElType *) malloc(capacity * sizeof(ElType));
    l->nEff = 0; 
    l->capacity = capacity; 
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(ListDin *l){
    free(l->buffer); 
    l->buffer = NULL; 
    l->capacity = 0; 
    l->nEff = 0; 

}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l){
    return l.nEff; 
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l){
    return 0; 

}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListDin l){
    return l.nEff - 1; 
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i){
    return (i >= 0 && i < l.capacity); 
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i){
    return (i >= 0 && i < l.nEff);
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
    return (listLength(l) == 0); 
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l){
    return (listLength(l) == l.capacity); 
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
    int n; 
    do {
        scanf("%d", &n);
    } while(n < 0 || n > l->capacity);

    l->nEff = n; 
    for (int i = 0; i < n; i++){
        scanf("%d", &l->buffer[i]); 
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
void printList(ListDin l){
    if (isEmpty(l)){
        printf("[]");
    }else{
        int len = listLength(l); 
        printf("[");
        for (int i = 0; i < len; i++){
            printf("%d", l.buffer[i]);
            if (i < len - 1){
                printf(",");
            }
        }
        printf("]");
    }
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
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    ListDin l3; 
    CreateListDin(&l3, l1.capacity);
    l3.nEff = l1.nEff; 
    int len = l1.nEff;
    for (int i = 0; i < len; i++){
        if (plus){
            l3.buffer[i] = l1.buffer[i] + l2.buffer[i];
        }else{
            l3.buffer[i] = l1.buffer[i] - l2.buffer[i];
        }
    }
    return l3; 
}
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
    if (l1.nEff != l2.nEff) return false;
    for (int i = 0; i < l1.nEff; i++){
        if (l1.buffer[i] != l2.buffer[i]){
            return false;
        }
    }
    return true; 

}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
    int len = l.nEff; 
    for (int i = 0; i < len; i++){
        if (l.buffer[i] == val){
            return i;
        }
    }
    return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min){
    *min = l.buffer[0];
    *max = l.buffer[0]; 
    for (int i = 1; i < l.nEff; i++){ 
        if (l.buffer[i] > *max){
            *max = l.buffer[i];
        }
        if (l.buffer[i] < *min){
            *min = l.buffer[i];
        }
    }

}
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
    CreateListDin(lOut, lIn.capacity);
    lOut->nEff = lIn.nEff;
    for (int i = 0; i < lIn.nEff; i++){
        lOut->buffer[i] = lIn.buffer[i];
    }
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
ElType sumList(ListDin l){
    int result = 0; 
    for (int i = 0; i < l.nEff; i++){
        result += l.buffer[i];
    }
    return result; 
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val){
    if (isEmpty(l)){
        return 0;
    }
    int count = 0;
    for (int i = 0; i < l.nEff; i++){
        if (l.buffer[i] == val){
            count++;
        }
    }
    return count;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
    int temp;
    int len = listLength(*l); 
    if (asc){
        bool swap; 
        for (int i  = 0; i < len - 1; i++){
            swap = false; 
            for (int j = 0; j < len - i - 1; j++){
                if (l->buffer[j] > l->buffer[j+1]){
                    temp = l->buffer[j + 1]; 
                    l->buffer[j + 1] = l->buffer[j]; 
                    l->buffer[j] = temp; 
                    swap = true; 
                }
            }
            if (swap == false){
                break; 
            }
        }
    }else{
        bool swap; 
        for (int i  = 0; i < len - 1; i++){
            swap = false; 
            for (int j = 0; j < len - i - 1; j++){
                if (l->buffer[j] < l->buffer[j+1]){
                    temp = l->buffer[j + 1]; 
                    l->buffer[j + 1] = l->buffer[j]; 
                    l->buffer[j] = temp; 
                    swap = true; 
                }
            }
            if (swap == false){
                break; 
            }
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
void insertLast(ListDin *l, ElType val){
    if (isFull(*l)) return; 
    l->buffer[l->nEff] = val; 
    l->nEff++; 
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val){
    if (isEmpty(*l)) return; 
    *val = l->buffer[l->nEff-1];
    l->nEff--;
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num){
    l->capacity += num; 
    l->buffer = realloc(l->buffer, l->capacity * sizeof(ElType));
}   
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num){
    if (l->capacity - num < l->nEff){
        return;
    }
    l->capacity -= num; 
    l->buffer = realloc(l->buffer, l->capacity * (sizeof(ElType)));
}
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDin *l){
    l->capacity = l->nEff; 
    l->buffer = realloc(l->buffer, l->capacity * (sizeof(ElType)));
}
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
