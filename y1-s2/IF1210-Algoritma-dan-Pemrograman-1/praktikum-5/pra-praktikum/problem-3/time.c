#include "boolean.h"
#include "time.h"
#include <stdio.h>

/* *** Definisi TYPE TIME <HH:MM:SS> *** */

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S) {
    if (H >= 0 && H <= 23 && M >= 0 && M <= 59 && S >= 0 && S <= 59 ) {
        return true;
    } else {
        return false;
    }
}
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int HH, int MM, int SS) {
    if (IsTIMEValid(HH, MM, SS) == true) {
        T->HH = HH;
        T->MM = MM;
        T->SS = SS;
    } 
}
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T) {
    int H = 99, M = 99, S = 99;
    do {
        scanf("%d %d %d", &H, &M, &S);

        if (IsTIMEValid(H, M, S) == false) {
            printf("Jam tidak valid\n");
        } 

    } while (IsTIMEValid(H, M, S) == false);

    CreateTime(T, H, M, S);
}
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */
   
void TulisTIME (TIME T) {
    printf("%02d:%02d:%02d", T.HH, T.MM, T.SS);
}
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T) {
    long sum = 3600*T.HH + 60*T.MM + T.SS;
    return sum;
}
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

TIME DetikToTIME (long N) {
    int N1 = N % 86400;
    
    //get hours
    int hrs = N1 / 3600;
    N1 = N1 % 3600;
    
    //get mins
    int mins = N1 / 60;
    N1 = N1 % 60;

    //get secs
    int secs = N1;

    TIME T;
    T.HH = hrs;
    T.MM = mins;
    T.SS = secs;

    return T;
} 
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2) {
    if (Hour(T1) == Hour(T2) && Minute(T1) == Minute(T2) && Second(T1) == Second(T2)) {
        return true;
    } else {
        return false;
    }
    /* Mengirimkan true jika T1=T2, false jika tidak */
}
boolean TNEQ (TIME T1, TIME T2) {
    if (Hour(T1) == Hour(T2) && Minute(T1) == Minute(T2) && Second(T1) == Second(T2)) {
        return false;
    } else {
        return true;
    }
    /* Mengirimkan true jika T1 tidak sama dengan T2 */
}
boolean TLT (TIME T1, TIME T2) {

    if (Hour(T1) < Hour(T2)) {
        return true;
    } else if (Hour(T1) > Hour(T2)) {
        return false;
    } else {
        if (Minute(T1) < Minute(T2)) {
            return true;
        } else if (Minute(T1) > Minute(T2)) {
            return false;
        } else {
            return (Second(T1) < Second(T2)) ? true : false;
        }
    }
    /* Mengirimkan true jika T1<T2, false jika tidak */
}
boolean TGT (TIME T1, TIME T2) {
    if (Hour(T1) < Hour(T2)) {
        return false;
    } else if (Hour(T1) > Hour(T2)) {
        return true;
    } else {
        if (Minute(T1) < Minute(T2)) {
            return false;
        } else if (Minute(T1) > Minute(T2)) {
            return true;
        } else {
            return (Second(T1) > Second(T2)) ? true : false;
        }
    }

    /* Mengirimkan true jika T1>T2, false jika tidak */
}
/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T) {
    TIME nextTime;
    Hour(nextTime) = Hour(T);
    Minute(nextTime) = Minute(T);
    Second(nextTime) = Second(T);


    if (T.SS == 59) {
        if (T.MM == 59) {
            if (T.HH == 23) {
                Hour(nextTime) = 0;
                Minute(nextTime) = 0;
                Second(nextTime) = 0;
            } else {
                Hour(nextTime) = Hour(T) + 1;
                Minute(nextTime) = 0;
                Second(nextTime) = 0; 
            }
        } else {
            Minute(nextTime) = Minute(T) + 1;
            Second(nextTime) = 0;
        }
    } else {
        Second(nextTime) = Second(T) + 1;
    }

    return nextTime;
}
/* Mengirim 1 detik setelah T dalam bentuk TIME */
TIME NextNDetik (TIME T, int N) {
    TIME nextTime;
    Hour(nextTime) = Hour(T);
    Minute(nextTime) = Minute(T);
    Second(nextTime) = Second(T);

    for (int i = 0; i < N; i++) {
        nextTime = NextDetik(nextTime);
    }
    return nextTime;
}
/* Mengirim N detik setelah T dalam bentuk TIME */
TIME PrevDetik (TIME T) {
    TIME prevTime;
    Hour(prevTime) = Hour(T);
    Minute(prevTime) = Minute(T);
    Second(prevTime) = Second(T);

    if (T.SS == 0) {
        if (T.MM == 0) {
            if (T.HH == 0) {
                Hour(prevTime) = 23;
                Minute(prevTime) = 59;
                Second(prevTime) = 59;
            } else {
                Hour(prevTime) = Hour(T) - 1;
                Minute(prevTime) = 59;
                Second(prevTime) = 59;
            }
        } else {
            Minute(prevTime) = Minute(T) - 1;
            Second(prevTime) = 59;
        }
    } else {
        Second(prevTime) = Second(T) - 1;
    }
    
    return prevTime;
}
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
TIME PrevNDetik (TIME T, int N) {
    TIME prevTime;
    Hour(prevTime) = Hour(T);
    Minute(prevTime) = Minute(T);
    Second(prevTime) = Second(T);
    
    for (int i = 0; i < N; i++) {
        prevTime = PrevDetik(prevTime);
    }

    return prevTime;
}
/* Mengirim N detik sebelum T dalam bentuk TIME */
/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh) {
    long sec_awal = TIMEToDetik(TAw);
    long sec_akhir = TIMEToDetik(TAkh);

    if (TGT(TAw, TAkh) == true) {
        sec_akhir += 24 * 3600; //tambahkan 24 jam 
    } 
    return sec_akhir - sec_awal;
    
}
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */

