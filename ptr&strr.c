#include <stdio.h>
#include <conio.h>

void main()
{
    char str[30] = "coumputer";
    char *p;
    int i;

    clrscr();

    p = str;

    for (i = 1; i <= 8; i++)
    {
        printf("\n\n p = %s", p);
        printf("\n *p = %c", *p);
        p++;
    }
    getch();
}