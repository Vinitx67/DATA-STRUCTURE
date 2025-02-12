#include <stdio.h>
#include <conio.h>

void main()
{
    int x = 100;
    int *p;
    clrscr();

    p = &x;

    printf("\n\n p = %u", p);
    printf("\n\n *p = %d", *p);

    *p = 123;
    printf("\n\n x = %d", x);
    getch();
}
