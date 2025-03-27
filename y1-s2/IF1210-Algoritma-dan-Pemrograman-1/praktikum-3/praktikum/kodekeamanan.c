#include <stdio.h>

int main() {

    long long N, target;
    scanf("%lld", &N);

    long long arr[N];
    for (int x = 0; x < N; x++) {
        long long num;
        scanf("%lld", &num);
        arr[x] = num;
    }

    scanf("%lld", &target);
    long long num1, num2;
    int found = 0;

    for (int i = 0; i < N && found != 1; i++) {
        for (int j = i + 1; j < N && found != 1; j++) {

            if (arr[i] + arr[j] == target) {
                num1 = i;
                num2 = j;
                found = 1;
            }

        }
    }

    printf("[");
    printf("%lld, ", num1);
    printf("%lld", num2);
    printf("]\n");

    return 0;
}