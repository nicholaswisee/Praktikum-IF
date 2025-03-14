#include <stdio.h>

int main() {

    int N;

    scanf("%d", &N);
    int now = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int min;
            
            if( N - i < j){
                min = i;
            }
            else{
                min = j;
            }

            now = now + min;
            printf("%d ", now);
            
        }
        printf("\n");
    }
    
    return 0;
}