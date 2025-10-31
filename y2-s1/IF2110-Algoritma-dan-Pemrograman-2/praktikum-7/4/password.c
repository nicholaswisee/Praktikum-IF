#include "password.h"
#include <stdio.h>

int length(int angka) {
    int len = 0;

    while (angka % 10 != 0) {
        angka /= 10;
        len++;
    }

    return len;
}

int getDigit(int angka, int index) {
    int temp = angka;
    int count = 0;
    do {
        temp /= 10;
        count++;
    } while (temp != 0);

    if (index >= count || index < 0) return -1;

    int mod = 1;
    for (int i = 0; i <= index; i++) {
        mod = mod*10;
    }

    // 1234 4-> 1234 mod 10 / 1, 3-> mod 100 / 10, 2-> mod 1000 / 100
    return (angka % mod / (mod/10));
}

int removeDigit(int angka, int index) {
    if (index < 0) return angka;

    int i = 0; 
    while (getDigit(angka, i) != -1) {
        if (getDigit(angka, i) == angka) break;
        i++;
    }

    int remainder = 1;
    for (int i = 0; i < index; i++) {
        remainder *= 10;
    }

    int headExp = 1;
    for (int i = 0; i <= index; i++) {
        headExp *= 10;
    }

    int tail = angka % remainder;
    int head = (angka / headExp) * remainder;

    return head + tail;

// i = index of number
// 1234 remove 1:
// remainder = 1234 mod 10^1
//  124 = (1234 / (10^1+1)) * 10^1 + remainder 
// 12345 remove 2:
// 1245 = 12345 / 10^2+1 * 10^2
}

void cariKombinasi(int angka, int current, int panjangAwal) {
    
}

void findPassword(int angka) {

}
