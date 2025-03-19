#include <stdio.h>
#include <math.h>

double konversi_suhu(double suhu, char awal, char akhir) {

    switch (awal)
    {
    case 'C':
        if (akhir == 'F') {
            suhu = (suhu * (9.0/5.0) )+ 32;
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
            suhu = (suhu - 32) * (5.0/9.0);
            break;
        } 
        else if (akhir == 'K') {
            suhu = (suhu - 32) * (5.0/9.0) + 273.15;
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
            suhu = ((suhu - 273.15) * (9.0/5.0)) + 32;
            break;
        }
        else {
            
            break;
        }

    default:
        break;
    }
    

    return floor(suhu);
}


int main() {

    int N;
    double temp;
    char awal, akhir;


    scanf("%d", &N);

    double temps[N];

    for (int i = 0; i < N; i++) {
        scanf("%lf", &temp);
        scanf(" %c", &awal);
        scanf(" %c", &akhir);
        temps[i] = konversi_suhu(temp, awal, akhir);
    }

    for (int j = 0; j < N; j++) {
        printf("%.2lf\n", temps[j]);
    }

    return 0;
}