#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const char *FLAG = "Orkom{XXXXXXXXXXXXXXXX}";

void win()
{
    printf("How did you get here!?\n");
    printf("Here's the flag: %s\n", FLAG);
}

void setup()
{
    setvbuf(stdin, NULL, 2, 0);
    setvbuf(stdout, NULL, 2, 0);
    setvbuf(stderr, NULL, 2, 0);
}

void print_menu()
{
    printf("=======================================\n");
    printf("=   AI-Powered Name Printer Program   =\n");
    printf("=                                     =\n");
    printf("= How to use:                         =\n");
    printf("= 1. Enter your name                  =\n");
    printf("= 2. Wait for a couple seconds        =\n");
    printf("= 3. Our AI-powered system will       =\n");
    printf("=    automatically print your name!   =\n");
    printf("= 4. Input 'stop' to stop using this  =\n");
    printf("=    program                          =\n");
    printf("=======================================\n");
}

int main()
{
    setup();

    int secret = 0XC0DEAB1E;

    char name[0x40];
    while (1)
    {
        print_menu();

        printf("What is your name?\n> ");
        scanf("%s", name);

        if (!strncmp(name, "stop", 4))
        {
            printf("Thank you for using our program!\n");
            break;
        }

        for (int i = 3; i > 0; i--)
        {
            printf("%d... ", i);
            sleep(1);
        }

        printf("\nInference completed! Your name is %s!\n", name);
    }

    if (secret != 0xC0DEAB1E)
    {
        exit(1);
    }
}