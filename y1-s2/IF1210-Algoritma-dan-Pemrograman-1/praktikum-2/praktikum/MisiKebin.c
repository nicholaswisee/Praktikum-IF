#include <stdio.h>

// TODO: Perbaiki prosedur agar variabel total bisa diperbarui secara langsung
long countPrime(long A, long B, long total) {
    // TODO: Implementasi prosedur untuk menghitung jumlah bilangan prima dalam rentang [A, B]
    // Saat ini, total tidak bisa diperbarui karena hanya merupakan salinan dari nilai di main()
    long count = 0; 
    long isPrime;

    if (A <= B) {

        for (long i = A; i <= B; i++) {
            isPrime = 0;
            
            for (long j = 1; j <= i; j++) {

                if (i % j == 0) {
                    isPrime += 1;
                } 
                
            }
            
            if (isPrime == 2) {
                count += 1;
            } 
            
        }
        
        return count;
    } 

    return 0;

}

int main() {
    long A, B, total;

    // TODO: Baca dua bilangan integer A dan B dalam satu baris
    // Input harus dalam format: "A B"

    // TODO: Perbaiki pemanggilan prosedur dengan menggunakan alamat variabel total
    // Agar perubahan nilai di dalam prosedur juga mempengaruhi nilai di main()
    
    scanf("%ld", &A);
    scanf(" %ld", &B);

    total = countPrime(A, B, total);

    printf("%ld\n", total);

    return 0;
}