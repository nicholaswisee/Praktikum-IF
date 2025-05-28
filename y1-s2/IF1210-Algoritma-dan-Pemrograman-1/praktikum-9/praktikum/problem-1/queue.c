#include "queue.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueue(Queue *q) {
    q->idxHead = IDX_UNDEF;
    q->idxTail = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(Queue q) {
    return (q.idxHead == IDX_UNDEF && q.idxTail == IDX_UNDEF);
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(Queue q) {
    if (q.idxHead == 0) {
        return (q.idxTail == CAPACITY - 1);
    } else {
        return (q.idxTail == q.idxHead - 1);
    }
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(Queue q) {
    if (isEmpty(q)) return 0;
    if (q.idxHead == q.idxTail) return 1;

    if (q.idxHead < q.idxTail) return (q.idxTail - q.idxHead + 1);

    // Jika melingkar
    // [0 1 2 3 4]
    return (CAPACITY - q.idxHead + q.idxTail + 1);
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val) {
    if (isFull(*q)) return;

    if (isEmpty(*q)) {
        q->buffer[0] = val;
        q->idxHead = 0;
        q->idxTail = 0;
    } else {
        q->idxTail = (q->idxTail + 1) % CAPACITY;
        q->buffer[q->idxTail] = val;
    }
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q mungkin penuh. Jangan lakukan apapun apabila penampung penuh. */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, ElType *val) {
    if (isEmpty(*q)) return;

    *val = q->buffer[q->idxHead];
    if (length(*q) == 1) {
        q->idxHead = IDX_UNDEF;
        q->idxTail = IDX_UNDEF;
    } else {
        q->idxHead = (q->idxHead + 1) % CAPACITY;
    }

}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, jangan lakukan apa-apa bila kosong*/
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q) {
    printf("[");

    if (!isEmpty(q)) {
        int i = q.idxHead;
        while (TRUE) {
            printf("%d", q.buffer[i]);
            if (i == q.idxTail) break;
            printf(",");
            i = (i + 1) % CAPACITY;
        }
    }

    printf("]\n");
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang setiap elemen queue, termasuk spasi dan enter */
/* Tambahkan \n ketika Queue sudah selesai di tulis */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
