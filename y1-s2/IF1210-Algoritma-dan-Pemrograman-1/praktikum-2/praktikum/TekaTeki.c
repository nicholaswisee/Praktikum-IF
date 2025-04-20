#include <stdio.h>

/**
 * Fungsi untuk menghitung kombinasi C(n, k) = n! / (k! * (n - k)!)
 * Note: jangan menggunakan perhitungan faktorial secara langsung, 
 * tetapi sederhanakan bentuk perhitungan kombinasi
 * @param n int
 * @param k int
 * @return Mengembalikan hasil kombinasi C(n, k) dalam bentuk long long
 */

long long kombinasi(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == n) return 1;
    long long top = 1, bottom = 1, edge, border;

    long long diff = n - k;

    if (diff > k) {
        edge = diff;
        border = k;
    } else {
        edge = k;
        border = diff;
    }

    for (int i = n; i >= 1; i--) {
        if (i > edge) {
            top *= i;
        } else if (i <= border ) {
            bottom *= i;
        } else {
            bottom *= 1;
        }
        
    }

    long long comb = top / bottom;

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

