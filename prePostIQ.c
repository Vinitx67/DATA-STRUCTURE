#include <stdio.h>
void main()
{
    int a = 2, b = 2;
    while (--a && b--)
    {
        printf("A: %d\n", a);
        printf("\nB: %d\n", b);
    }
    printf("\nA: %d\n", a);
    printf("\nB: %d\n", b);
}