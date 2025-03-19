#include <stdio.h>
#include "MandiBola.h"

void SelamatDatang(int n) {

    printf("----------------------------------------\n");
    printf("Selamat datang di Wahana Mandi Bola!\n");
    printf("\n");
    printf("Silakan beli tiket terlebih dahulu untuk masuk ke wahana ini.\n");
    printf("\n");
    printf("Harga tiket:\n");
    printf("- Anak-anak (usia 0-12 tahun): Rp 10000\n");
    printf("- Dewasa (usia 13-64 tahun): Rp 20000\n");
    printf("- Lansia (usia 65 tahun ke atas): Rp 15000\n");
    printf("\n");

}


int main() {
    
    int input_1;
    long input_2;
    scanf("%d", &input_1);
    scanf("%ld", &input_2);
    SelamatDatang(input_1);
    HandleNimonsHunting(input_2);


    return 0;
}