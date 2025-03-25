#include <stdio.h>
#include <string.h>

 
/**
 * Fungsi untuk mengecek apakah tahun kabisat
 * @param int year
 * @return 1 jika tahun kabisat, 0 jika bukan
 */
int isLeapYear(int year) {
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
 * Fungsi untuk mendapatkan jumlah hari dalam bulan tertentu
 * @param int month, year
 * @param int year
 * @return total hari dalam bulan tertentu
 */
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // continue here ...
    if (isLeapYear(year) == 1 && month == 2) {
        return daysInMonth[month] + 1;
    }
    else {
        return daysInMonth[month];
    }
}


/**
 * Fungsi untuk mengecek apakah suatu tanggal valid
 * @param int day
 * @param int month
 * @param int year
 * @return 1 jika valid, 0 untuk sebaliknya
 */
int isValidDate(int day, int month, int year) {
    if ( day >= 1 && day <= getDaysInMonth(month, year) && month >= 1 && month <= 12 && year >= 1) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Fungsi untuk mendapatkan hari dalam seminggu menggunakan Zeller’s Congruence
 * @param int day
 * @param int month
 * @param int year
 * @return string berupa hari apa pada tanggal tersebut
 */
const char* getDayOfWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int K = year % 100;
    int J = year / 100;
    int h = (day + (13 * (month + 1)) / 5 + K + (K / 4) + (J / 4) - (2 * J)) % 7;
    
    const char* days[] = {"Sabtu", "Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat"};
    return days[h];
}

/**
 * Fungsi untuk mendapatkan zodiak berdasarkan tanggal
 * @param int day
 * @param int month
 * @return string berupa zodiak dari tanggal tersebut
 */
const char* getZodiac(int day, int month) {
    const char* zodiacSigns[] = {
        "Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini",
        "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn"
    };
    int zodiacStartDays[] = {20, 19, 21, 20, 21, 21, 23, 23, 23, 23, 22, 22, 20};

    if (day < zodiacStartDays[month - 1]) return zodiacSigns[month - 1];
    return zodiacSigns[month];
}

/**
 * Fungsi untuk menghitung jumlah hari sejak 01-01-0001
 * @param int day
 * @param int month
 * @param int year
 * @return total hari sejak 01-01-0001 sampai tanggal yang diberikan
 */
long long daysFromBeginning(int day, int month, int year) {
    // type your code here...
    int daysCount = 0;

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
 * Fungsi untuk menghitung selisih hari antara dua tanggal
 * @param int d1
 * @param int m1
 * @param int y1
 * @param int d2
 * @param int m2
 * @param int y2
 * @return total selisih hari dari tanggal ke 1 menuju tanggal ke 2
 */
long long dateDifference(int d1, int m1, int y1, int d2, int m2, int y2) {
    //type your code here...
    long long firstDaysCount = daysFromBeginning(d1, m1, y1);
    long long secondDaysCount = daysFromBeginning(d2, m2, y2);
    long long difference = secondDaysCount - firstDaysCount;
    return difference;
}

/**
 * Fungsi untuk menghitung hari pasaran Jawa
 * @param int day
 * @param int month
 * @param int year
 * @return string hari pasaran jawa berdasarkan tanggal yang diberikan
 */
const char* getPasaran(int day, int month, int year) {
    const char* pasaran[] = {"Legi", "Pahing", "Pon", "Wage", "Kliwon"};
    int daysCount = daysFromBeginning(day, month, year);
    int hariPasaran = daysCount % 5;

    return pasaran[hariPasaran];
    //continue here...

}

/**
 * Gunakan strcmp(string1, string2) untuk mengecek apakah kedua string sama
 * Contoh:
 * strcmp("sabtu", "sabtu") --> 0
 * strcmp("senin", "sabtu") --> 1
 */
int main() {
    // type your code here...
    char perintah[16];
    int d1, d2, m1, m2, y1, y2;
    scanf("%s", perintah);
    
    while (strcmp(perintah, "SELESAI") != 0) {
        if (strcmp(perintah, "VALIDASI") == 0) {

            scanf("%d", &d1);
            scanf(" %d", &m1);
            scanf(" %d", &y1);

            int valid = isValidDate(d1, m1, y1);
            if (valid == 1) {
                printf("YA\n");
            } else {
                printf("TIDAK\n");
            }

        } else if (strcmp(perintah, "HARI") == 0) {
            scanf("%d", &d1);
            scanf(" %d", &m1);
            scanf(" %d", &y1);

            const char* day = getDayOfWeek(d1, m1, y1);
            printf("%s\n", day);

        } else if (strcmp(perintah, "ZODIAK") == 0) {
            scanf("%d", &d1);
            scanf(" %d", &m1);
  
            const char* zodiac = getZodiac(d1, m1);
            printf("%s\n", zodiac);

        } else if (strcmp(perintah, "SELISIH") == 0) {
            scanf("%d", &d1);
            scanf(" %d", &m1);
            scanf(" %d", &y1);
            scanf(" %d", &d2);
            scanf(" %d", &m2);
            scanf(" %d", &y2);

            long long selisih = dateDifference(d1, m1, y1, d2, m2, y2);
            printf("%lld\n", selisih);

        } else if (strcmp(perintah, "PASARAN") == 0) {
            scanf("%d", &d1);
            scanf(" %d", &m1);
            scanf(" %d", &y1);

            const char* pasaran = getPasaran(d1, m1, y1);
            printf("%s\n", pasaran);
        }
        scanf("%s", &perintah);
    }

    return 0;
}