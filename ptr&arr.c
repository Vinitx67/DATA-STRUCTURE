#include <stdio.h>
#include <conio.h>

void main()
{
    int x[5] = {10, 20, 30, 40, 50};
    int *p, i;

    clrscr();

    p = &x[0];

    for (i = 1; i <= 5; i++)
    {
        printf("\n\n p = %u", p);
        printf("\n\n *p = %d", *p);
        p++;
    }
    getch();
}