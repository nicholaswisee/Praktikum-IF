#include "line.h"
#include "boolean.h"
#include "point.h"
#include <math.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */ 
/* ***************************************************************** */
/* *** Konstruktor membentuk LINE *** */
void CreateLine (LINE * L, POINT P1, POINT P2) {
    L->PAw = P1;
    L->PAkh = P2;
}
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaLINE (LINE * L) {
    POINT P1;
    POINT P2;

    do {
        BacaPOINT(&P1);
        BacaPOINT(&P2);

        if (EQ(P1, P2) == true) {
            printf("Invalid Line\n");
        }

    } while (EQ(P1, P2) == true);
    CreateLine(L, P1, P2);
}
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai LINE yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk LINE yang valid 
   LINE disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan line tidak valid, diberikan pesan kesalahan: 
   "Invalid Line" */
/* Contoh:
   2 3
   2 3
   Invalid Line
   2 3
   3 3 
   --> terbentuk line L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */

void TulisLINE (LINE L) {
    printf("(");
    TulisPOINT(PAwal(L));
    printf(",");
    TulisPOINT(PAkhir(L));
    printf(")");
}
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */

/* *** Kelompok operasi line *** */
float PanjangLINE (LINE L) {
    POINT P1 = PAwal(L);
    POINT P2 = PAkhir(L);
    
    float distance_x = P1.X - P2.X;
    float distance_y = P1.Y - P2.Y;
    float distance = sqrt((distance_x * distance_x) + (distance_y * distance_y));
    return distance;
} 
/* Menghitung panjang line L : berikan rumusnya */
float Gradien (LINE L) {
    if (PAwal(L).X == PAkhir(L).X) {
        return;
    } else {
        float x_diff = L.PAkh.X - L.PAw.X;
        float y_diff = L.PAkh.Y - L.PAw.Y;
        float grad = (y_diff/x_diff);
        return grad;
    }
} 
/* Mengembalikan Gradien (m) dari L */
/* Gradien line yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
void GeserLINE (LINE * L, float deltaX, float deltaY) {
    Geser(&(L->PAw), deltaX, deltaY);
    Geser(&(L->PAkh), deltaX, deltaY);
}
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
/* Proses : PAw dan PAkh digeser. */

/* *** Kelompok predikat *** */
boolean IsTegakLurus (LINE L1, LINE L2) {
    float grad_L1 = Gradien(L1);
    float grad_L2 = Gradien(L2);

    return (grad_L1 * grad_L2) == -1 ? true : false;
}
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua line saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
boolean IsSejajar (LINE L1, LINE L2) {
    float grad_L1 = Gradien(L1);
    float grad_L2 = Gradien(L2);

    return (grad_L1 == grad_L2) ? true : false;

}
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua line saling sejajar jika memiliki gradien yang sama */
