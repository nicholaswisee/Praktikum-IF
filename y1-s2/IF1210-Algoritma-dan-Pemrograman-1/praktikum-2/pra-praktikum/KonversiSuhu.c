#include <stdio.h>
#include <math.h>

double konversi_suhu(double suhu, char awal, char akhir) {

    switch (awal)
    {
    case 'C':
        if (akhir == 'F') {
            suhu = (suhu * 9/5 ) + 32;
            break;
        }
            else if (akhir == 'K') {
            suhu = suhu + 273.15;
            break;
        } else {
            break;
        }

    case 'F':
        if (akhir == 'C') {
            suhu = (suhu - 32) * 5/9;
            break;
        } 
        else if (akhir == 'K') {
            suhu = ((suhu - 32) * 5/9) + 273.15;
            break;
        }
        else {
            break;
        }

    case 'K':
        if (akhir == 'C') {
            suhu = suhu - 273.15;
            break;
        }    
        else if (akhir == 'F') {
            suhu = ((suhu - 273.15) * 9/5) + 32;
            break;
        }
        else {
            
            break;
        }

    default:
        break;
    }
    

    return suhu;
}


int main() {

    int N;
    double temp;
    char awal, akhir;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%lf %c %c", &temp, &awal, &akhir);
        printf("%.2lf\n", floor(konversi_suhu(temp, awal, akhir)));
    }


    return 0;
}