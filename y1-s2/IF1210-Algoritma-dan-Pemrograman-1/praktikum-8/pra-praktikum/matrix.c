#include "matrix.h"
#include "Boolean.h"
#include <stdio.h>
#include <stdlib.h>

void createMatrix(int nRows, int nCols, Matrix *m) {
    if (nRows < 1 || nRows > ROW_CAP || nCols < 1 || nCols > COL_CAP) return;

    m->rowEff = nRows;
    m->colEff = nCols;
}

/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j) {
    return (i < ROW_CAP && j < COL_CAP && i >= 0 && j >= 0);
}
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m) {
    return (m.rowEff - 1);
}
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(Matrix m) {
    return (m.colEff - 1);
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
    return (i < m.rowEff && j < m.colEff && i >= 0 && j >= 0);
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, IdxType i) {
    return m.mem[i][i];
}
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut) {
    for (int i = 0; i < mIn.rowEff; i++) {
        for (int j = 0; j < mIn.colEff; j++) {
            mOut->mem[i][j] = mIn.mem[i][j];
        }
    }
    mOut->rowEff = mIn.rowEff;
    mOut->colEff = mIn.colEff;
}
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */ 
void readMatrix(Matrix *m, int nRow, int nCol) {
    if (!isMatrixIdxValid(nRow, nCol)) return;

    createMatrix(nRow, nCol, m);
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            scanf("%d", &m->mem[i][j]);
        }
    }
}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m) {
    for (int i = 0; i < m.rowEff; i++) {
        for (int j = 0; j < m.colEff; j++) {
            printf("%d", m.mem[i][j]);
            if (j < m.colEff - 1) printf(" ");
        }
        if (i < m.rowEff - 1) printf("\n");
    }
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2) {
    if (m1.rowEff != m2.rowEff || m1.colEff != m2.colEff) return;
    Matrix result;
    createMatrix(m1.rowEff, m1.colEff, &result);
    for (int i = 0; i < m1.rowEff; i++) {
        for (int j = 0; j < m1.colEff; j++) {
            result.mem[i][j] = m1.mem[i][j] + m2.mem[i][j];
        }
    }

    return result;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2) {
     if (m1.rowEff != m2.rowEff || m1.colEff != m2.colEff) return;

    Matrix result;
    createMatrix(m1.rowEff, m1.colEff, &result);
    for (int i = 0; i < m1.rowEff; i++) {
        for (int j = 0; j < m1.colEff; j++) {
            result.mem[i][j] = m1.mem[i][j] - m2.mem[i][j];
        }
    }

    return result;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMatrix(Matrix m1, Matrix m2) {

    Matrix result;
    createMatrix(m1.rowEff, m2.colEff, &result);

    for (int i = 0; i < m1.rowEff; i++) {
        for (int j = 0; j < m2.colEff; j++) {
            int sum = 0;
            for (int k = 0; k < m1.colEff; k++) {
                sum += m1.mem[i][k] * m2.mem[k][j];
            }
            result.mem[i][j] = sum;
        }
    }

    return result;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyByConst(Matrix m, ElType x) {
    Matrix result;
    createMatrix(m.rowEff, m.colEff, &result);

    for (int i = 0; i < m.rowEff; i++) {
        for (int j = 0; j < m.colEff; j++) {
            result.mem[i][j] = x * m.mem[i][j];
        }
    }

    return result;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyByConst(Matrix *m, ElType k) {
    for (int i = 0; i < m->rowEff; i++) {
        for (int j = 0; j < m->colEff; j++) {
            m->mem[i][j] = m->mem[i][j] * k;
        }
    }
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2) {
    if (m1.rowEff != m2.rowEff || m1.colEff != m2.colEff) return FALSE;

    for (int i = 0; i < m1.rowEff; i++) {
        for (int j = 0; j < m1.colEff; j++) {
            if (m1.mem[i][j] != m2.mem[i][j]) return FALSE; 
        }
    }

    return TRUE;
}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
    return !(isMatrixEqual(m1, m2));
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
    return (m1.rowEff == m2.rowEff && m1.colEff == m2.colEff);
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmt(Matrix m) {
    return m.rowEff * m.colEff;
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m) {
    return (m.rowEff == m.colEff);
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric(Matrix m) {
    if (!isSquare(m)) return FALSE;

    for (int i = 0; i < m.rowEff; i++) {
        for (int j = 0; j < m.colEff; j++) {
            if (m.mem[i][j] != m.mem[j][i]) return FALSE;
        }
    }

    return TRUE;
}
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity(Matrix m) {
    if (!isSquare(m)) return FALSE;

    for (int i = 0; i < m.rowEff; i++) {
        for (int j = 0; j < m.colEff; j++) {
           if (i != j) {
                if (m.mem[i][j] != 0) return FALSE;
           } else {
                if (m.mem[i][j] != 1) return FALSE;
           }
        }
    }

    return TRUE;
}
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse(Matrix m) {
    int count = 0;
    
    for (int i = 0; i < m.rowEff; i++) {
        for (int j = 0; j < m.colEff; j++) {
            if (m.mem[i][j] != 0) count++;
        }
    }

    if (countElmt(m) == 0) return TRUE;
    float eff = (float) count / countElmt(m);

    return (eff <= 0.05);
}
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix negation(Matrix m) {
    Matrix result;
    createMatrix(m.rowEff, m.colEff, &result);
    copyMatrix(m, &result);

    result = multiplyByConst(result, -1);

    return result;
}
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void pNegation(Matrix *m) {
    pMultiplyByConst(m, -1);
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
float determinant(Matrix m) {
    if (!isSquare(m)) return 0;
    float result; 

    if (m.rowEff == 1)  {
        result = (float) m.mem[0][0];
    } 

    else if (m.rowEff == 2) {
        result = (float) (m.mem[0][0] * m.mem[1][1]) - (m.mem[0][1] * m.mem[1][0]);
    }
    
    else {
        result = 0;
        //submatrix method go brrr
        for (int i = 0; i < m.colEff; i++) {
            Matrix subMatrix;
            createMatrix(m.rowEff - 1, m.colEff - 1, &subMatrix);
            int curRow = 0, curCol = 0;

            for (int j = 1; j < m.rowEff; j++) {
                for (int k = 0; k < m.colEff; k++) {
                    if (k != i) {
                        subMatrix.mem[curRow][curCol++] = m.mem[j][k];
                    }
                }
                curCol = 0;
                curRow++;
            }

            result += ((i % 2 == 0) ? 1 : -1) * m.mem[0][i] * determinant(subMatrix);
            //selang-seling pos neg        
        }
    }

    return result;
    
    /* 
    Penjelasan:
    Hitung determinan pake submatrix,
    buat submatrix baru dengan ukuran row-1 dan col-1,
    yang diambil selalu baris pertama, jadi elemen yang diambil
    untuk membuat submatrix = di bawah baris pertama (makanya mulai dari 1),
    dan tidak sekolom dengan elemen tersebut (k != i).

    kalo blm ngerti metode submatrix pelajarin dulu hehee
    */
} 
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
Matrix transpose(Matrix m) {
    if (!isSquare(m)) return m;

    Matrix result;
    createMatrix(m.colEff, m.rowEff, &result);
    for (int i = 0; i < m.rowEff; i++) {
        for (int j = 0; j < m.colEff; j++) {
            result.mem[j][i] = m.mem[i][j];
        }
    }

    return result;
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
void pTranspose(Matrix *m) {
    if (!isSquare(*m)) return;
    Matrix copy;
    copyMatrix(*m, &copy);
    for (int i = 0; i < m->rowEff; i++) {
        for (int j = 0; j < m->colEff; j++) {
            m->mem[j][i] = copy.mem[i][j];
        }
    }
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */