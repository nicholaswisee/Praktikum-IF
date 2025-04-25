#include <stdio.h>

int main(){
    float j, v;
    int t;
    scanf("%f", &v);
    scanf("%d", &t);
    
    j = v * t;

    printf("%.2f\n", j);
    return 0;
}