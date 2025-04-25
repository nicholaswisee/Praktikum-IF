#include <stdio.h>

int main(){
    int h1, m1, s1, h2, m2, s2, h3, m3, s3;
    scanf("%d %d %d", &h1, &m1, &s1);
    scanf("%d %d %d", &h2, &m2, &s2);
    h3 = h2-h1;
    m3 = m2-m1;
    s3 = s2-s1;
    printf("%d %d %d\n", h3, m3, s3);

    return 0;
}