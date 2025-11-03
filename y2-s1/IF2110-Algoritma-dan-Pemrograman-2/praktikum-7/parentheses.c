#include <stdio.h>

// long long untuk menghindari overflow pada nilai besar
long long countComb(int n) {
	// base case
	if (n == 0) return 0;
	if (n == 1) return 1;

	long long total = 0;

	/// Menggunakan persamaan Catalan: C(n) = Zigma (C(i) * C(n-1-i)) , i dari 0 sampai n-1 -> solusi klasik untuk pertanyaan pasangan kurung
	for (int i = 0; i < n; i++) {
		long long left = countComb(i);
		long long right = countComb(n - 1 - i);

		// Jika kiri/kanan 0, berarti hanya ada 1 cara.
		if (left == 0) left = 1;
		if (right == 0) right = 1;

		total += left * right;
	}
	return total;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", countComb(n));
}