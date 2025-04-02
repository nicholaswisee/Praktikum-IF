#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1001

int countInstances(char* arr, char find, int len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] == find) {
            count += 1;
        }
    }
    return count;
}

int main() {
    char s[MAX_SIZE];
    scanf("%s", s);
    int len = strlen(s);

    int freq[256] = {0}; 

    for (int i = 0; i < len; i++) {
        freq[(unsigned char)s[i]]++;
    }
    

    int oddcount = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] % 2 != 0) {
        oddcount++;
    }
}

    if (oddcount <= 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }   

    return 0;
}