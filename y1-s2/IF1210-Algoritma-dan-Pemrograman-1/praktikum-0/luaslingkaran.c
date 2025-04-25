#include <stdio.h>

int main(){
    const float pi = 3.1415;

    float r, luas;
    scanf("%f", &r);
    luas = pi*r*r;
    printf("%f\n", luas);

    return 0;
}