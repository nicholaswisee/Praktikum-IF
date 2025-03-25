#include <stdio.h>

/**
 * Fungsi untuk mengecek apakah tahun kabisat
 * Untuk tahun kelipatan 100, tahun kabisat harus habis dibagi 400
 * Untuk tahun selain kelipatan 100, tahun kabisat harus habis dibagi 4
 * @param year Tahun
 * @return Mengembalikan 1 jika tahun kabisat, 0 jika tidak
 */
int isLeapYear(int year)
{
  // TODO: Implementasi fungsi isLeapYear
    if (year % 100 == 0) {
        if (year % 400 == 0) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (year % 4 == 0) {
            return 1;
        } else {
            return 0;
        }
    }
}

/**
 * Fungsi untuk mendapatkan jumlah hari dalam suatu bulan
 * @param month Bulan (dalam rentang 1-12)
 * @param year Tahun
 * @return Mengembalikan jumlah hari dalam bulan tersebut
 */
int getDaysInMonth(int month, int year)
{
  // TODO: Implementasi fungsi getDaysInMonth
  switch (month) {
    case 1:
    return 31;
        break;
    case 2:
        if (isLeapYear(year) == 1) {
            return 29;
            break;            
        } else {
            return 28;
            break;
        }
    case 3:
        return 31;
        break;
    case 4:
        return 30;
        break;
    case 5:
        return 31;
        break;
    case 6:
        return 30;
        break;
    case 7:
        return 31;
        break;
    case 8:
        return 31;
        break;
    case 9:
        return 30;
        break;
    case 10:
        return 31;
        break;
    case 11:
        return 30;
        break;
    case 12:
        return 31;
        break;    
    default:
        break;
  }

}

/**
 * Mengembalikan apakah tanggal valid
 * Tanggal yang valid mengikuti aturan berikut:
 * - 1 <= day <= jumlah hari dalam bulan
 * - 1 <= month <= 12
 * - year >= 1
 * @param day The day
 * @param month The month
 * @param year The year
 * @return mengembalikan 1 jika tanggal valid, 0 jika tidak
 */
int isValidDate(int day, int month, int year) {
  // TODO: Implementasi fungsi isValidDate
    if ( day >= 1 && day <= getDaysInMonth(month, year) && month >= 1 && month <= 12 && year >= 1) {
        return 1;
    } else {
        return 0;
    }

}

/**
 * Fungsi untuk menghitung jumlah hari sejak awal, yaitu day = 1, month = 1, year = 1
 * @param day Hari
 * @param month Bulan
 * @param year Tahun
 * @return Mengembalikan jumlah hari sejak awal
 */
long long daysFromBeginning(int day, int month, int year) {
  // TODO: Implementasi fungsi daysFromBeginning
    long long daysCount = 0;

    for (int i = 1; i <= year; i++) {

        if (i != year) {

        for (int j = 1; j <= 12; j++) {
            daysCount += getDaysInMonth(j, i);    

            }

        }
        
        else { //i == year

            for (int j = 1; j <= month; j++) {
                
                if (j != month) {
                    daysCount += getDaysInMonth(j, i);
                } else { // j == month
                    daysCount += day;
                }
            }
        } 
    }
    
    return daysCount;
}

/**
 * Fungsi untuk menghitung perbedaan hari dari dua tanggal yang valid (tanggal 2 - tanggal 1)
 * Note: input tanggal sudah valid
 * @param d1 Hari dari tanggal pertama
 * @param m1 Bulan dari tanggal pertama
 * @param y1 Tahun dari tanggal pertama
 * @param d2 Hari dari tanggal kedua
 * @param m2 Bulan dari tanggal kedua
 * @param y2 Tahun dari tanggal kedua
 * @return Mengembalikan perbedaan hari dari tanggal 2 - tanggal 1
 */
long long dateDifference(int d1, int m1, int y1, int d2, int m2, int y2)
{
  // TODO: Implementasi fungsi dateDifference
    long long firstDaysCount = daysFromBeginning(d1, m1, y1);
    long long secondDaysCount = daysFromBeginning(d2, m2, y2);
    long long difference = secondDaysCount - firstDaysCount;
    return difference;

}

/**
 * Program utama:
 * - Menerima input d1,m1,y1
 * - Validasi tanggal pertama sampai input valid
 * - Menerima input d2,m2,y2
 * - Validasi tanggal kedua sampai input valid dan tanggal kedua lebih besar atau sama dengan dari tanggal pertama
 * - Mengeluarkan output selisih hari dari tanggal kedua - tanggal pertama
 */
int main() {
//   TODO: Implementasi program utama
    int d1, m1, y1, d2, m2, y2;
    int valid1 = 0, valid2 = 0;

    while (valid1 != 1 || valid2 != 1) {
        
        while (valid1 != 1) {

            scanf("%d", &d1);
            scanf(" %d", &m1);
            scanf(" %d", &y1);
            if (isValidDate(d1, m1, y1) == 0) {
                printf("Tanggal tidak valid\n");
            } else {
                valid1 = 1;
            }
            
        }   
        
        while (valid2 != 1) {
            scanf("%d", &d2);
            scanf(" %d", &m2);
            scanf(" %d", &y2);
            
            if (isValidDate(d2, m2, y2) == 0) {
                printf("Tanggal tidak valid\n");
            } else {
                valid2 = 1;
            }
        }

        long long daysDifference = dateDifference(d1, m1, y1, d2, m2, y2);

        while (daysDifference < 0) {
            printf("Tanggal kedua lebih dulu\n");

            scanf("%d", &d2);
            scanf(" %d", &m2);
            scanf(" %d", &y2);


            if (isValidDate(d2, m2, y2) == 0) { 
                printf("Tanggal tidak valid\n");
            } else {
                valid2 = 1;
            }

            daysDifference = dateDifference(d1, m1, y1, d2, m2, y2);
        }

        printf("%lld\n", daysDifference);
    }
    return 0;
}