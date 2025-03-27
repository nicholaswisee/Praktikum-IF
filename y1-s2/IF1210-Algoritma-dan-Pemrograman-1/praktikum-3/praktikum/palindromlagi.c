#include <stdio.h>
#include <string.h>

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
    char s[1001];
    scanf("%s", s);
    int len = strlen(s);
    int oddcount = 0;
    int checked[1001] = {0}; 

    for (int i = 0; i < len; i++) {
        if (checked[i] == 1) continue; 
        
        char searched = s[i];
        int count = countInstances(s, searched, len);
        checked[i] = 1;
        
        for (int j = i + 1; j < len; j++) {
            if (s[j] == searched) {
                checked[j] = 1;
            }
        }

        if (count % 2 != 0) {
            oddcount += 1;
        }
    }

    if (oddcount <= 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }   

    return 0;
}