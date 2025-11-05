#include <stdio.h>

int n;

void generateSubset(int start, int k, int depth, int n, int *arr, int *subset) {
    if (depth == k) {
        printf("[");
        for (int i = 0; i < k; i++) {
            if (i) printf(",");
            printf("%d", subset[i]);
        }
        printf("]\n");
        return;
    }
    for (int i = start; i <= n - (k - depth); i++) {
        subset[depth] = arr[i];
        generateSubset(i + 1, k, depth + 1, n, arr, subset);
    }
}


int main() {	
	scanf("%d", &n);
    
	int arr[11];
	int subset[11];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int k = 0; k <= n; k++) {
        generateSubset(0, k, 0, n, arr, subset);
    }
    return 0;
}