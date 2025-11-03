#include "password.h"
#include <stdio.h>

int main() {	
	int angka;
	printf("Masukkan angka: ");
	scanf("%d", &angka);
	findPassword(angka);
	
	return 0;
}