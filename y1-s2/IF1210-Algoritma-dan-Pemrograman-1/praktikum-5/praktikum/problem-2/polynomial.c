#include "polynomial.h"
#include <math.h>

void CreatePolynomial(Polynomial *p) {
    for (int i = 0; i < MAX_DEGREE + 1; i++) {
        p->coeff[i] = 0;
    }
    p->degree = 0;
}
/**
 * I.S. -
 * F.S. Terbentuk polynomial p dengan semua koefisien diinisialisasi dengan 0.0
 * dan degree juga diinisialisasi dengan 0
 */

void CreatePolynomialFromArray(Polynomial *p, int coeffArray[], int size) {
    CreatePolynomial(p);

    for (int i = 0; i < size; i++) {
        p->coeff[i] = coeffArray[i];
    }

    for (int i = size - 1; i >= 0; i--) {
        if (p->coeff[i] != 0) {
            p->degree = i;
            return;
        }
    }

    p->degree = 0;
}
/**
 * I.S. CoeffArray adalah array of coefficients yang terdefinisi, 
 * size adalah ukuran dari coeffArray yang terdefinisi
 * F.S. Terbentuk polynomial p dengan semua koefisien diinisialisasi berdasarkan coeffArray
 * dan degree diinisialisasikan dengan index tertinggi dari elemen coeffArray yang tidak nol
 */

/* Selektor */
int GetCoefficient(Polynomial *p, int exponent) {
    return p->coeff[exponent];
}
/**
 * Mengembalikan nilai koefisien pada suku dengan eksponen = exponent
 */

int GetDegree(Polynomial *p) {
    return p->degree;
}
/**
 * Mengembalikan derajat tertinggi dari polynomial dengan koefisien tak nol
 */

int Evaluate(Polynomial *p, int x) {
    int totalSum = 0;
    for (int i = 0; i <= p->degree; i++) {
        totalSum += p->coeff[i] * pow(x, i);
    }
    return totalSum;
}
/**
 * Mengembalikan hasil evaluasi polynomial p dengan masukan x
 * Contoh: 
 * p = 3x^2 + 3x + 1
 * Evaluate(p, 1) = 3(1^2) + 3(1) + 1 = 7
 */

/* Mutator */
void SetCoefficient(Polynomial *p, int exponent, int coefficient) {
    if (exponent < 0 || exponent > MAX_DEGREE) return;

    p->coeff[exponent] = coefficient;
    if (exponent > p->degree && coefficient != 0) {
        p->degree = exponent;
    }
    if (exponent == p->degree && coefficient == 0) {
        while (p->degree > 0 && p->coeff[p->degree] == 0) {
            p->degree--;
        }
    }
}
/**
 * I.S. Polynomial p, exponent, dan coefficient terdefinisi
 * F.S. Polynomial p diupdate dengan koefisien baru (coefficient)
 * pada suku dengan eksponen yang diberikan (exponent)
 */

/* Operasi Baca/Tulis */
void ReadPolynomial(Polynomial *p) {
    CreatePolynomial(p);
    int size;

    do {
        scanf("%d", &size);
    } while (size < 0 || size > MAX_DEGREE);

    for (int i = 0; i < size; i++) {
        scanf("%d", &p->coeff[i]);
    }

    for (int i = size - 1; i >= 0; i--) {
        if (p->coeff[i] != 0) {
            p->degree = i;
            break;
        }
    }
} 
/**
 * I.S. Polynomial p belum terdefinisi
 * F.S. Polynomial p terdefinisi dan diisi dengan nilai-nilai yang dibaca dari input
 * - Meminta input size yang merupakan banyak koefisien yang akan dimasukkan (dari koefisien 0)
 * - Meminta input koefisien sebanyak size dan menginisialisasi p berdasarkan nilai ini (dari koefisien 0)
 */

/* Operator Aritmatika */
void AddPolynomials(Polynomial *p1, Polynomial *p2, Polynomial *result) {
    CreatePolynomial(result);
    result->degree = GetDegree(p1) >= GetDegree(p2) ? p1->degree : p2->degree; 
    
    for (int i = 0; i <= result->degree; i++) {
        result->coeff[i] = p1->coeff[i] + p2->coeff[i];
    }

    while (result->degree > 0 && result->coeff[result->degree] == 0) {
        result->degree--;
    }
}
/**
 * I.S. Polynomial p1 dan p2 terdefinisi
 * F.S. Hasil penjumlahan p1 dan p2 (p1 + p2) disimpan di polynomial result
 */

void SubtractPolynomials(Polynomial *p1, Polynomial *p2, Polynomial *result) {
    CreatePolynomial(result);
    result->degree = GetDegree(p1) >= GetDegree(p2) ? p1->degree : p2->degree; 
    
    for (int i = 0; i <= result->degree; i++) {
        result->coeff[i] = p1->coeff[i] - p2->coeff[i];
    }

    while (result->degree > 0 && result->coeff[result->degree] == 0) {
        result->degree--;
    }
}
/**
 * I.S. Polynomial p1 dan p2 terdefinisi
 * F.S. Hasil pengurangan p1 dan p2 (p1 - p2) disimpan di polynomial result
 */

int IsEqual(Polynomial *p1, Polynomial *p2) {
    if (p1->degree != p2->degree) {
        return 0;
    } else {
        for (int i = 0; i <= p1->degree; i++) {
            if (p1->coeff[i] != p2->coeff[i]) {
                return 0;
            }
        }
        return 1;
    }
}
/**
 * I.S. Polynomial p1 dan p2 terdefinisi
 * F.S. Mengembalikan 1 jika kedua polynomial adalah sama, dan 0 jika sebaliknya
 * Dua polynomial dianggap sama jika keduanya memiliki derajat yang sama dan semua koefisiennya bernilai sama
 */

/* Operasi Lain */
void PrintPolynomial(Polynomial *p) {
    int first = 1;
    for (int i = p->degree; i >= 0; i--) {
        if (p->coeff[i] == 0) continue;
        
        if (!first) {
            if (p->coeff[i] > 0) printf(" + ");
            else printf(" - ");
        } else {
            if (p->coeff[i] < 0) printf("-");
            first = 0;
        }

        int absCoeff = abs(p->coeff[i]);
        
        if (absCoeff != 1 || i == 0) {
            printf("%d", absCoeff);
        }

        if (i > 0) {
            printf("x");
            if (i > 1) printf("^%d", i);
        }
    }
    if (first == 1) printf("0");

    printf("\n");
}
/*
 * I.S. P terdefinisi
 * F.S. Polynomial p ditampilkan dengan aturan sebagai berikut:
 * - Elemen ditampilkan dari derajat paling tinggi ke derajat paling rendah
 * - Hanya tampilkan elemen dengan koefisien tak nol
 * - Untuk suku derajat tertinggi (pertama ditampilkan) dengan koefisien positif, tidak perlu berikan tanda + di depan
 * - Untuk suku derajat tertinggi (pertama ditampilkan) dengan koefisien negatif, tidak perlu berikan spasi antara tanda - dan suku (-x^n)
 * - Untuk suku yang bukan derajat tertinggi, tampilkan tanda + dan - dengan diberikan spasi (x^3 + 6x)
 * - Untuk koefisien 1, hanya tampilkan x^n (bukan 1x^n), kecuali untuk suku konstan
 * - Untuk koefisien -1, hanya tampilkan -x^n atau - x^n (bukan -1x^n dan - 1x^n), kecuali untuk suku konstan
 * - Untuk suku derajat 1, tampilkan x (bukan x^1)
 * - Untuk suku derajat 0, tampilkan koefisiennya saja
 * - Berikan newline (\n) di akhir baris
 * Contoh: -4x^3 + 3x^2 - 2x + 1
 * */