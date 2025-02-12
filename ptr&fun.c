#include <stdio.h>
#include <conio.h>

void swap(int *, int *);

void main()
{
    int a = 10, b = 20;

    clrscr();

    printf("\n values before swap :");
    printf("\n\n a = %d", a);
    printf("\n\n b = %d", b);

    swap(&a, &b);
    printf("\n values after swap :");
    printf("\n\n a = %d", a);
    printf("\n\n b = %d", b);

    getch();
}

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}