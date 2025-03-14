#include <stdio.h>
#include <math.h>
#include <string.h>
// #include <std

int main() {

    int N, length, check, palindrome = 1;

    scanf("%d", &N);
    length = log10(N) + 1;
    int M = 0; int temp;
    check = N;
    for(int i = 1; i <= length; i++){
        temp = N % 10;
        N = N/10;
        for(int j = 1; j <= length - i; j++){
            temp = temp * 10;
        }
        M += temp;
    }
    if(M - check == 0){
        printf("%d\n", 1);
    }
    else{
        printf("%d\n", 0);
    }
    // printf("%d", palind
    return 0;
}