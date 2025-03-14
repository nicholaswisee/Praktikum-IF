#include <stdio.h>
#include <math.h>

int main() {
    int N;
    int count = 1;
    scanf("%d", &N);

    for (int i = 2; i <= N; i++) {
        if (N % i == 0) {
            int root = sqrt(i);
            if (root * root == i)
            {
                count++;
            }
            
        }
    }
    printf("%d\n", count);

    return 0;
}