
#include "Boolean.h"
#include "matrix.h"
#include "kalkulus.h"

Matrix dilate(Matrix v, int scale) {
    Matrix Vektor;
    copyMatrix(v, &Vektor);
    multiplyByConst(Vektor, scale);
    return Vektor;
}
/* Setiap titik (x, y) menjadi (x*scale, y*scale) */

Matrix translate(Matrix v, int dx, int dy) {
    Matrix Vektor;
    copyMatrix(v, &Vektor);
    for (int i = 0; i < v.rowEff; i++) {
        for (int j = 0; j < v.colEff; j++) {
            if (j == 0){
                Vektor.mem[i][j] = v.mem[i][j] + dx;
            } else{
                Vektor.mem[i][j] = v.mem[i][j] + dy;
            }
        }
    }
    return Vektor;
}
/* Setiap titik (x, y) menjadi (x+dx, y+dy) */

Matrix reflect(Matrix v, char axis){
    Matrix result;
    copyMatrix(v, &result);
    for (int i = 0; i < v.rowEff; i++) {
        for (int j = 0; j < v.colEff; j++) {
            if (axis == 'x' && j == 1){
                result.mem[i][j] = -v.mem[i][j];
            }
            if (axis == 'y' && j == 0){
                result.mem[i][j] = -v.mem[i][j];
            }
        }
    }

    return result;
}
/* 'x' → y = -y, 'y' → x = -x */

Matrix rotate(Matrix v, int degree){
    Matrix Vektor;
    copyMatrix(v, &Vektor);    
    switch (degree) {
        case 0: 
            return Vektor;
            break;
        case 90:
            for (int i = 0; i < v.colEff; i++) {
                Vektor.mem[i][0] = v.mem[i][1];
                Vektor.mem[i][1] = -v.mem[i][0]; 
            }
            return Vektor;
            break;
        case 180:
            for (int i = 0; i < v.colEff; i++) {
                Vektor.mem[i][0] = -v.mem[i][0];
                Vektor.mem[i][1] = -v.mem[i][0]; 
            }
            return Vektor;
            break;
        case 270:
            for (int i = 0; i < v.colEff; i++) {
                Vektor.mem[i][0] = -v.mem[i][1];
                Vektor.mem[i][1] = v.mem[i][0]; 
            }
            return Vektor;
            break;
    }
}
/* Memutar setiap titik (x, y) sebesar degree derajat searah jarum jam dari (0,0) */
/* Gunakan rumus rotasi:
   x' = x * cosθ + y * sinθ
   y' = -x * sinθ + y * cosθ
   degree hanya 0, 90, 180, 270 (bisa pakai konstanta tanpa trigonometri float) */
/* cos0 = 1, sin0 = 0*/
/* cos90 = 0, sin90 = 1*/
/* cos180 = -1, sin180 = 0*/
/* cos270 = 0, sin270 = -1*/
/* DEGREE SUDAH PASTI 4 JENIS, HARDCODE SAJA, TIDAK PERLU PAKE <math.h> */
