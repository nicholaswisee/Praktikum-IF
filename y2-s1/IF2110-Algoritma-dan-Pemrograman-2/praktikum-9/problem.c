/* File: problem.c */
/* Implementasi fungsi untuk merotasi linked list ke kanan sebanyak k posisi */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Fungsi untuk merotasi linked list ke kanan sebanyak k posisi.
 * Rotasi ke kanan artinya elemen-elemen terakhir dipindahkan ke depan.
 * 
 * I.S.  : l terdefinisi, mungkin kosong; k >= 0
 * F.S.  : Mengembalikan list baru yang merupakan hasil rotasi l sebanyak k posisi ke kanan.
 *         List asli l tidak dimodifikasi (fungsional approach).
 *         Jika k lebih besar dari panjang list, gunakan k modulo panjang list.
 *
 * Contoh:
 * Jika l adalah [1,2,3,4,5] dan k=2, maka hasil [4,5,1,2,3]
 * Jika l adalah [1,2,3,4,5] dan k=0, maka hasil [1,2,3,4,5]
 * Jika l adalah [1,2,3,4,5] dan k=7, maka hasil [4,5,1,2,3] (karena 7 % 5 = 2)
 */

List removeLast(List l, ElType *last) {
    // Prekondisi: l tidak kosong
    if (isOneElmt(l)) {
        *last = INFO(l);
        return NIL; // sisa list-nya kosong
    } else {
        ElType temp;
        List rest = removeLast(NEXT(l), &temp);

        List newHead = newNode(INFO(l));
        NEXT(newHead) = rest;

        *last = temp;
        return newHead;
    }
}

List rotateOnce(List l) {
    if (isEmpty(l) || isOneElmt(l)) return copy(l);

    ElType last;
    List withoutLast = removeLast(l, &last);

    return konso(last, withoutLast);
}

List rotateRight(List l, int k) {
    int n = length(l);
    if (n == 0 || n == 1) return copy(l);

    k %= n;
    if (k == 0) return copy(l);

    // rotasi rekursif k kali
    List rest = rotateRight(l, k - 1);
    List result = rotateOnce(rest);

    return result;
}
