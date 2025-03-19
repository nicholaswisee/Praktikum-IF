//ARGHA
#include <stdio.h>
#include "MandiBola.h"


int HitungBiayaTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
    return(jumlah_anak * 10000 + jumlah_dewasa * 20000 + jumlah_lansia * 15000);
}

void PrintTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
    printf("Tiket berhasil dibeli!\n");
    printf("Rincian:\n");
    printf("- Jumlah anak-anak: %d\n", jumlah_anak);
    printf("- Jumlah dewasa: %d\n", jumlah_dewasa);
    printf("- Jumlah lansia: %d\n", jumlah_lansia);
    printf("- Total biaya: %d\n", HitungBiayaTiket(jumlah_anak, jumlah_dewasa, jumlah_lansia));
}

void SelamatDatang(int input){

    int jumlah_lansia = (input - input%100)/100;
    int jumlah_dewasa = (input%100 - input%10)/10;
    int jumlah_anak = (input%10);

    if (input >= 0 && input <= 999 ) {
        printf("----------------------------------------\n");
        printf("Selamat datang di Wahana Mandi Bola!\n");
        printf("\n");
        printf("Silakan beli tiket terlebih dahulu untuk masuk ke wahana ini.\n");
        printf("\n");
        printf("Harga tiket:\n");
        printf("- Anak-anak (usia 0-12 tahun): Rp 10000\n");
        printf("- Dewasa (usia 13-64 tahun): Rp 20000\n");
        printf("- Lansia (usia 65 tahun ke atas): Rp 15000\n");
        printf("Jumlah anak: %d\n", jumlah_anak);
        printf("Jumlah dewasa: %d\n", jumlah_dewasa);
        printf("Jumlah lansia: %d\n", jumlah_lansia);
        
        PrintTiket(jumlah_anak, jumlah_dewasa, jumlah_lansia);
    }
}


void HandleNimonsHunting(long input){
 
    printf("----------------------------------------\n");
    printf("Selamat datang di Treasure Hunting Nimons!\n");
    printf("\n");
    

    long temp = input;
    long langkah, gerak, harta, tutup, harga;
    long jumlah_lubang_ditutup = 0; long total_harta_karun = 0; long total_langkah = 0;
    long total_harga_harta_karun; long total_biaya_ganti_rugi;

    long jumlah_pergerakan = input % 10;
    printf("Jumlah pergerakan Nimons di dalam kolam: %ld\n", jumlah_pergerakan);
    temp /= 10;

    long jumlah_lubang = input % 10;
    temp /= 10;
    printf("Jumlah lubang yang ada di kolam: %ld\n", jumlah_lubang);

    long jumlah_harta_karun = temp % 10;
    temp /= 10;
    printf("Jumlah harta karun yang ada di kolam: %ld\n", jumlah_harta_karun);

    for (int i = 1; i <= jumlah_pergerakan; i++) {
        langkah = temp % 1000;
        temp /= 1000;
        gerak = langkah % 10;
        harta = (langkah % 100 - langkah % 10) / 10;
        tutup = (langkah - langkah % 100) / 100; 

        printf("Langkah ke-%d\n", i);

        if (gerak == 0) {
            printf("Nimons tidak bergerak\n");
        } else {
            printf("Nimons bergerak sejauh %ld langkah\n", gerak);
            total_langkah += gerak;
        }

        if (harta == 1) {
            printf("Nimons menemukan harta karun!\n");
            total_harta_karun += 1;
        }

        if (tutup == 1) {
            printf("Nimons menutup lubang!\n");
            jumlah_lubang_ditutup += 1;
        }
    }
    printf("\n");

    harga = temp;

    total_harga_harta_karun = total_harta_karun * harga * 5;
    total_biaya_ganti_rugi = harga * jumlah_lubang_ditutup;

    printf("Total lubang yang ditutup: %ld dari %ld lubang\n", jumlah_lubang_ditutup, jumlah_lubang);
    printf("TOtal harta karun yang ditemukan: %ld\n", total_harta_karun);
    printf("Total harga harta karun yang ditemukan: %ld\n", total_harga_harta_karun);
    printf("Total langkah yang ditempuh: %ld\n", total_langkah);
    printf("Total biaya ganti rugi Pak Gro: %ld\n", total_biaya_ganti_rugi);
    printf("Total keuntungan Nimons dan Pak Gro: %ld\n", total_harga_harta_karun - total_biaya_ganti_rugi);


    
}
