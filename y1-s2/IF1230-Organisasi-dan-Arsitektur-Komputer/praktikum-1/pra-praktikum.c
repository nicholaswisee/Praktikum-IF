// Pra-Praktikum 1 IF1230 Organisasi dan Arsitektur Komputer
// Topic: Bitwise Operations

// sein - Alternatif operasi XOR (x ^ y) menggunakan hanya |, &, dan ~.
// XOR berfungsi sebagai operasi "exclusive or", yang menghasilkan 1 jika hanya salah satu dari x atau y yang bernilai 1.
// Jika kedua bit sama (0-0 atau 1-1), hasilnya adalah 0.

// Contoh:
// sein(5, 3)  = 6   (0101 ^ 0011 = 0110)
// sein(10, 7) = 13  (1010 ^ 0111 = 1101)
// sein(0, 0)  = 0   (0000 ^ 0000 = 0000)
// sein(15, 8) = 7   (1111 ^ 1000 = 0111)

// Legal ops	: | & ~
// Max ops	: 5
// Rating		: 2

int sein(int x, int y) {
    return (x | y) & ~(x & y);
}
int test_sein(int x, int y) {
    return x ^ y;
}

// stark - Mengubah bilangan x menjadi 0 jika negatif, dan membiarkannya tetap jika positif.
// Jika x negatif, return 0.
// Jika x positif atau nol, return x.

// Contoh:
// stark(-5) = 0
// stark(-10) = 0
// stark(3) = 3
// stark(0) = 0

// Legal ops    	: | & ~ << >> ^
// Max ops      	: 5
// Rating      	: 2

int stark(int x) {
    return x & ~(x >> 31);
}
int test_stark(int x) {
    return (x >= 0) ? x : 0;
}

// fern - Menukar setiap bit genap dengan bit ganjil dalam bilangan x.
// Bit pada posisi genap dan ganjil dipertukarkan.
// Bit pada posisi genap (0, 2, 4, ...) akan berpindah ke posisi ganjil (1, 3, 5, ...).
// Bit pada posisi ganjil (1, 3, 5, ...) akan berpindah ke posisi genap (0, 2, 4, ...).

// Contoh:
// fern(0b1010) = 0b0101
// fern(0b1100) = 0b1100
// fern(0b1111) = 0b1111
// fern(0b1001) = 0b0110

// Legal ops   	: | & ~ << >>
// Max ops      	: 6
// Rating       	: 3

unsigned int fern(unsigned int x) {
    return ((x & 0xAAAAAAAA) >> 1) | ((x & 0x55555555) << 1);
}
unsigned int test_fern(unsigned int x) {
    unsigned int result = 0;
    for (int i = 0; i < 32; i += 2) {
        unsigned int even_bit = (x >> i) & 1;
        unsigned int odd_bit = (x >> (i + 1)) & 1;
        result |= (even_bit << (i + 1)) | (odd_bit << i);
    }
    return result;
}

// aura - Menentukan apakah jumlah bit "1" dalam representasi biner x adalah ganjil.
// Jika jumlah bit "1" dalam x adalah ganjil, return 1.
// Jika jumlah bit "1" dalam x adalah genap, return 0.

//  Contoh:
// aura(5)  = 1  (101 -> 2 bit "1", genap)
// aura(7)  = 0  (111 -> 3 bit "1", ganjil)
// aura(10) = 1  (1010 -> 2 bit "1", genap)
// aura(15) = 0  (1111 -> 4 bit "1", genap)

// Legal ops    	: | & ~ << >> ^
// Max ops      	: 15
// Rating       	: 3

int aura(unsigned int x) {
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 1;
}
int test_aura(unsigned int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count % 2;
}

// ubel - Membalik bit dalam 32-bit unsigned integer.
// Setiap bit dalam bilangan akan dibalik dari posisi awalnya.
// Bit paling kanan menjadi bit paling kiri, dan sebaliknya.

// Contoh:
// ubel(0b00000010100101000001111010011100) = 0b00111001011110000010100101000000
// ubel(0b11110000111100001111000011110000) = 0b00001111000011110000111100001111
// ubel(0b00000000000000000000000000000001) = 0b10000000000000000000000000000000

// Legal ops    	: Loop, | & ~ << >> ^ ! + -
// Max ops      	: 40
// Rating       	: 3

unsigned int ubel(unsigned int n) {
   unsigned int result = 0;
   int i;
    for (i = 0; i < 32; i++)
        result |= ((n >> i) & 1) << (31 - i);
    return result;
}
unsigned int test_ubel(unsigned int n) {
    unsigned int result = 0;
    for (int i = 0; i < 32; i++) {
        result |= ((n >> i) & 1) << (31 - i);
    }
    return result;
}


