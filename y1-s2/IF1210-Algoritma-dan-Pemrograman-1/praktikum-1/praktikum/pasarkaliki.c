#include <stdio.h>

int main() {

    int N, comb;

    scanf("%d", &N);

    if (N < 1 || N > 60) {
        return 0;
    }

    for (int n = 0; n < N; n++) {
        
        int C = 1; 
      
        for (int j = (N - n - 2); j >= 0; j--) {
            printf(" ");
        }
        
        for (int k = 0; k <= n; k++) {
            printf("%d", C);
            
            C = C * (n - k) / (k + 1);
            
            if (k < n) {
                printf(" ");
            }
        }
        
        printf("\n");
    }
    
    return 0;
    
} 

//cuma 70 :(
