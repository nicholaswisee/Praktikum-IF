#include <stdio.h>

long HitungTotal(long a, long b, long c, long d, long e) {
    return a + b + c + d + e;
}

double HitungRata(long total) {
    double avg = total / 5;

    return avg;
}

void TampilkanPesan(long total, double avg) {
    printf("%ld\n", total);
    printf("%lf\n", avg);

    if (avg >= 10) {
        printf("Pesta Nimons Sukses!\n");

    } else {
        printf("Pesta Nimons Gagal, kumpulkan lebih banyak pisang!\n");
    }

}

int main() {
    long a, b, c, d, e, total;
    double avg;

    scanf("%ld", &a);
    scanf("%ld", &b);
    scanf("%ld", &c);
    scanf("%ld", &d);
    scanf("%ld", &e);

    total = HitungTotal(a, b, c, d, e);
    avg = HitungRata(total);

    TampilkanPesan(total, avg);


    return 0;
}