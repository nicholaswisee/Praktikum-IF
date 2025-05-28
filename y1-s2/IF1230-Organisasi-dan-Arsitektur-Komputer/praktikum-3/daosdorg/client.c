#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const char *FLAG = "Orkom{XXXXXXXXXXXXXXXX}";

char message[128];

__asm__("pop %rdi;"
        "ret");

void win(int a, char *b)
{
    char *flag = FLAG;

    if (a != 0xCAFECAFE)
    {
        printf("Incorrect!\n");
        exit(1);
    }

    if (strcmp(b, "level 5 gyatt rizz"))
    {
        printf("Incorrect!\n");
        exit(1);
    }

    printf("Darn it... Three times in a row!\n");
    printf("Here's the flag: %s\n", flag);
}

__asm__("pop %rsi;"
        "ret");

void setup()
{
    setvbuf(stdin, NULL, 2, 0);
    setvbuf(stdout, NULL, 2, 0);
    setvbuf(stderr, NULL, 2, 0);
}

int main()
{
    setup();

    char name[0x20];

    printf("Since you keep breaking my program, i'll make it so that you can only run this program once!\n");

    printf("What is your name?\n> ");
    scanf("%s", name);

    for (int i = 3; i > 0; i--)
    {
        printf("%d... ", i);
        sleep(1);
    }

    printf("Hello, %s!\n", name);

    printf("And what's the message for the next person?\n> ");
    scanf("%[^\n]", message);
}