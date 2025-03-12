#include <stdio.h> 

int main() {
    
    int A;
    int B;
    int pita;
    int bigger;

    scanf("%d", &A);
    scanf("%d", &B);

    if (A > B) {
        bigger = A;
    } else {
        bigger = B;

    }

    for (int i = 1; i < bigger; i++) {
        if ( (A % i == 0) && (B % i == 0)) {
            pita = i;
        }
    }

    printf("%d\n", pita);

    return 0;

}