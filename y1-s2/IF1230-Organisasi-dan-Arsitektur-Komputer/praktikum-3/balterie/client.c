#include <stdio.h>

const char *FLAG = "Orkom{XXXXXXXXXXXXXXXX}";

int x, y;

void print_menu()
{
    printf("===========================\n");
    printf("= Simple Calculator App   =\n");
    printf("= 1. Add two numbers      =\n");
    printf("= 2. Subtract two numbers =\n");
    printf("===========================\n");
    printf("> ");
}

void setup()
{
    setvbuf(stdin, NULL, 2, 0);
    setvbuf(stdout, NULL, 2, 0);
    setvbuf(stderr, NULL, 2, 0);
}

void add()
{
    printf("Result: %d\n", x + y);
}

void subtract()
{
    printf("Result: %d\n", x - y);
}

int main()
{
    setup();

    int secret = 0xBADCAFE;

    short n;
    while (1)
    {
        print_menu();
        scanf("%d", &n);

        if (n != 1 && n != 2)
        {
            printf("This feature has not been implemented!\n");
            break;
        }

        printf("Enter the first number: ");
        scanf("%d", &x);

        printf("Enter the second number: ");
        scanf("%d", &y);

        if (n == 1)
            add();
        else
            subtract();
    }

    if (secret == 0xBADC0DE)
    {
        printf("Wha... How do you do that!?\n");
        printf("Anyway, here's the flag: %s\n", FLAG);
    }
}