#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *FLAG = "Orkom{XXXXXXXXXXXXXXXX}";

void win()
{
    printf("You've defeated me 6 times, congratulations i guess (╥﹏╥)\n");
    printf("Here's the flag: %s\n", FLAG);
}

void print_menu()
{
    printf("================================================\n");
    printf("=   Blockchain Powered Financial Tracker App   =\n");
    printf("=                                              =\n");
    printf("=   Presenting our latest product:             =\n");
    printf("= A blockchain powered financial tracker app t =\n");
    printf("= hat securely stores your spendings on a dece =\n");
    printf("= ntralized ledger, ensuring tamper-proof hist =\n");
    printf("= ory and transparent access control!          =\n");
    printf("=----------------------------------------------=\n");
    printf("= User choices:                                =\n");
    printf("= 1. Insert spending                           =\n");
    printf("= 2. View spending                             =\n");
    printf("= 3. Exit app                                  =\n");
    printf("================================================\n");
}

void write(unsigned *spendings, char **notes, char *used, short index)
{
    unsigned spending;
    printf("Enter total spending: ");
    scanf("%d", &spending);

    spendings[index] = spending;

    char buffer[32];
    printf("Enter spending note: ");
    scanf("%31s", buffer);

    notes[index] = malloc(strlen(buffer) + 1);

    strcpy(notes[index], buffer);

    printf("Spending saved successfully!\n");

    used[index] = 1;
}

void read(unsigned *spendings, char **notes, char *used, short index)
{
    if (!used[index])
    {
        printf("No spending has been recorded on this index!\n");
        return;
    }

    printf("Spending note for index %d\n", index);
    printf("Total spending: %u\n", spendings[index]);
    printf("Spending note: ");
    printf(notes[index]);
    printf("\n");
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

    unsigned spendings[32] = {0};
    char *notes[32] = {0};
    char used[32] = {0};

    int uinput;
    while (1)
    {
        print_menu();

        printf("User input: ");
        scanf("%d", &uinput);

        if (uinput == 1)
        {
            int index;
            do
            {
                printf("Enter note index (0-31): ");
                scanf("%d", &index);
            } while (index > 32);

            write(spendings, notes, used, index);
        }
        else if (uinput == 2)
        {
            int index;
            do
            {
                printf("Enter note index (0-31): ");
                scanf("%d", &index);
            } while (index > 32);

            read(spendings, notes, used, index);
        }
        else if (uinput == 3)
        {
            printf("Thank you for using our program!\n");
            break;
        }
        else
        {
            printf("Invalid input!\n");
        }
    }
}
