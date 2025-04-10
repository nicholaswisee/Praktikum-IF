#include <stdio.h>
#define MAX_LEN 100
#define MAX_LINE 100

int main() {

    FILE * file = fopen("text.txt", "r");

    if (file == NULL) {
        printf("Error in opening file\n");
        return 1;
    }

    char data[MAX_LINE][MAX_LEN];
    
    int line = 0;
    while (fgets(data[line], MAX_LINE, file) != NULL) {
        line++;
    }

    for (int i = 0; i < line; i++) {
        printf("%s", data[i]);
    }

    return 0;
}