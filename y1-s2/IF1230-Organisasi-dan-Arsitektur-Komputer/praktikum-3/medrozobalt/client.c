#include <stdio.h>
#include <string.h>
#include <unistd.h>

const char *FLAG = "Orkom{XXXXXXXXXXXXXXXX}";

void win()
{
    printf("No way... STOP BREAKING MY PROGRAMS!\n");
    printf("Here's the flag: %s\n", FLAG);
}

void lose()
{
    printf("Haha, no flag for you!\n");
}

void setup()
{
    setvbuf(stdin, NULL, 2, 0);
    setvbuf(stdout, NULL, 2, 0);
    setvbuf(stderr, NULL, 2, 0);
}

int main()
{
    setup();

    char input[0x20];
    char buffer[0x20];

    void (*function)() = lose;

    printf("This program will only run twice!\n");

    char c, j, n;
    for (int i = 0; i < 2; i++)
    {
        printf("=== String Palindrome Checker ===");

        printf("Enter your string: ");
        j = 0;
        while (1)
        {
            if (read(0, &c, 1) <= 0 || c == '\n')
                break;

            input[j++] = c;
        }

        n = strlen(input);
        for (j = 0; j < n; j++)
            buffer[0x20 - j - 1] = input[j];

        if (strncmp(input, buffer, 0x20))
        {
            printf("%s and %s are not palindromes\n", input, buffer);

            function();
        }
        else
        {
            printf("The two strings are palindromes!\n");
            printf("Since you're so good at this, I'll give you a free leak!\n");
            printf("It's not like you can bypass this anyway!\n");
            fgets(input, 0x80, stdin);
        }
    }
}