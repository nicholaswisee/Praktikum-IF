#include "point.h"
#include "boolean.h"
#include <math.h>

/* Membentuk POINT P dengan komponen X dan Y */
void CreatePoint(POINT *P, float X, float Y) {
    P->X = X;
    P->Y = Y;
};

/* Membaca nilai POINT dari stdin: masukkan X Y */
void BacaPOINT(POINT *P) {
    scanf("%f %f", &(P->X), &(P->Y));
}

/* Menulis POINT ke stdout dalam format "(X,Y)" */
void TulisPOINT(POINT P) {
    printf("(%f,%f)", P.X, P.Y);
}

/* Mengambil / mengubah komponen X dan Y */
float GetX(const POINT P) {
    return P.X;
}
float GetY(const POINT P) {
    return P.Y;
}
void  SetX(POINT *P, float X) {
    P->X = X;
}
void  SetY(POINT *P, float Y) {
    P->Y = Y;
}

/* Mengecek lokasi POINT pada sumbu atau kuadran */
boolean IsOrigin(POINT P) {
    if (P.X == 0 && P.Y == 0) {
        return true;  /* true jika P = (0,0) */
    } else {
        return false;
    }
}     
boolean IsOnSbX(POINT P) {
    if (P.Y == 0) {
        return true; /* true jika Y = 0 */
    } else {
        return false;
    } 
}      
boolean IsOnSbY(POINT P) {
    if (P.X == 0) {
        return true; /* true jika X = 0 */ 
    } else {
        return false;
    }
}      
int Kuadran(POINT P) {
    if (IsOrigin(P) != true && IsOnSbX(P) != true && IsOnSbY(P) != true) {
        if (P.X > 0) {
            return P.Y > 0 ? 1 : 4;
        } else {
            return P.Y > 0 ? 2 : 3; 
        }
    } else {
        return 0;
    }
    /* 1..4; prekondisi: P bukan origin dan tidak di sumbu */
}     
    
/* Membandingkan dua POINT */
boolean Equals(POINT P1, POINT P2) {
    if (P1.X == P2.X && P1.Y == P2.Y) {
        return true;
    } else {
        return false;
    }
    /* true jika X dan Y identik */
}  
boolean NonEquals(POINT P1, POINT P2) {
    if (Equals(P1, P2) == true) {
        return false;
    } else {
        return true;
    }
}

/* Menghitung jarak Euclidean antara P1 dan P2, Gunakan fungsi sqrtf dari math.h untuk menghitung akar kuadrat */
float  Distance(POINT P1, POINT P2) {
    float distance_x = P1.X - P2.X;
    float distance_y = P1.Y - P2.Y;
    float distance = sqrt((distance_x * distance_x) + (distance_y * distance_y));
    return distance;
}

/* Menghasilkan titik tengah P1 dan P2 */
POINT MidPoint(POINT P1, POINT P2) {
    POINT P3;
    P3.X = (P1.X + P2.X)/2.0;
    P3.Y = (P1.Y + P2.Y)/2.0;
    return P3;
}

