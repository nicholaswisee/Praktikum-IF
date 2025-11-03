#include <stdio.h>

int n;

void generateSubset(int idx, int subset_len, int subset[], int arr[]) {
	
	// gw gapaham lg gmn caranya men
	if (idx < 0) {
        printf("[");
        for (int i = subset_len - 1; i >= 0; i--) { 
            printf("%d", subset[i]);
            if (i > 0) printf(",");
        }
        printf("]\n");
		return;
	}
	
	// Pilihan 1: tidak ambil arr[idx]
	generateSubset(idx - 1, subset_len, subset, arr);
	
    // Pilihan 2: ambil arr[idx]
    subset[subset_len] = arr[idx];
    generateSubset(idx - 1, subset_len + 1, subset, arr);
	
}

int main() {	
	scanf("%d", &n);
    
	int arr[11];
	int subset[11];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	generateSubset(n - 1, 0, subset, arr);
	return 0;
}