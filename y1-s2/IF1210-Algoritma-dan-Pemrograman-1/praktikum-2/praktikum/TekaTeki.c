#include <stdio.h>

/**
 * Fungsi untuk menghitung kombinasi C(n, k) = n! / (k! * (n - k)!)
 * Note: jangan menggunakan perhitungan faktorial secara langsung, 
 * tetapi sederhanakan bentuk perhitungan kombinasi
 * @param n int
 * @param k int
 * @return Mengembalikan hasil kombinasi C(n, k) dalam bentuk long long
 */

long long fact(int j) {
    long long res = 1;
    if (j > 1) {

        for (int i = j; i > 1; i--) {
            res *= i;
        }
        return res;    
    }
    else {
        return 1;
    }
}

long long kombinasi(int n, int k) {
    if (k < 0 || k > n) return 0;
    
    long long comb = (fact(n))/ (fact(k) * fact(n-k)); 
    return comb;
    
}

/**
 * Fungsi untuk menghitung bilangan Catalan ke-N
 * Catalan(N) = C(2N, N) / (N + 1)
 * @param n int
 * @return Mengembalikan Catalan(n)
 */
long long catalan(int n) {
    long long val = kombinasi(2*n, n) / (n + 1);
    return val;
}
