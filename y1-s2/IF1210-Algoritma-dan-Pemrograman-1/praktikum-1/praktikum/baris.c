#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    

    if (N < 0 || N >= 100) {
        return 1;
    }
    

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int value = 1;
            
            for (int sum = 0; sum < i+j; sum++) {

                for (int r = 0; r <= sum; r++) {
                    int c = sum - r;
                    if (r < N && c < N) {
                        value++;
                    }
                }
            }
            
            for (int r = 0; r < i; r++) {
                int c = i+j - r;
                if (r < N && c < N) {
                    value++;
                }
            }
            
            printf("%d", value);
            if (j < N - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}

//terimakasih claude.ai kamu sangat hebat!