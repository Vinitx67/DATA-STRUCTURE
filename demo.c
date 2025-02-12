#include <stdio.h>
#include <conio.h>

void main()
{
    int x[5] = {10, 20, 30, 40, 50};

    clrscr();

    printf("\n\n x = %d", *(x + 0));
    printf("\n\n x = %d", *(x + 1));
    printf("\n\n x = %d", *(x + 2));
    printf("\n\n x = %d", *(x + 3));
    printf("\n\n x = %d", *(x + 4));

    getch();
}