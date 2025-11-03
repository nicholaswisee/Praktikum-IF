#include "password.h"
#include <stdio.h>

int length(int angka) {
    if (angka == 0) return -1;
	int len = 0;

  do {
    angka /= 10;
    ++len;
  } while (angka != 0);

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
	int len = length(angka);
	// Kalo udah abis digitnya, print current
	if (len == -1) {
        printf("%d\n", current);
        return;
    }

/*
123 -> i = 0 -> 3: cariKombinasi(12, 3, 3)
					cariKombinasi(1, 32, 3); --> 321
					cariKombinasi(2, 31, 3); --> 312
dst
*/

	for (int i = 0; i < len; i++) {
        int d = getDigit(angka, i);
        int newAngka = removeDigit(angka, i);
        int newCurrent = current * 10 + d;
        cariKombinasi(newAngka, newCurrent, panjangAwal);
    }
}

void findPassword(int angka) {
    int len = length(angka);
    cariKombinasi(angka, 0, len);
}
