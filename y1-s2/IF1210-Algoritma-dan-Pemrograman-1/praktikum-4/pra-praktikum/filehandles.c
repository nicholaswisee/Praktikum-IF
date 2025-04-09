#include <stdio.h>

int main() {

    FILE *fh_output; //assign fh_output as a file
    
    fh_output = fopen("io.txt", "w"); //open file in write mode
    int condition = 1;

    while (condition) {
        int num;
        printf("Enter a number (-1 quits): ");
        scanf("%d", &num);
        if (num == -1) break; 
        else fprintf(fh_output, "%d\n", num); //print out the line
    }
    
    fclose(fh_output);  //close file opened

    FILE *fh_input; //assign fh_input as file
    fh_input = fopen("io.txt", "r"); //open io.txt in read mode

    int finput = 0;
    int lines = 0;
    int numbers[100];

    while (fscanf(fh_input, "%d", &finput) != EOF) { //read file by scanf every line and assigning it to finput until it reaches EOF
        numbers[lines] = finput; //input the value read in the line into the array
        printf("File line %d: %d\n", lines+1, finput); //print the value that has just been put into the array
        lines++;
    }

    fclose(fh_output);  //close file

    return 0;
}

