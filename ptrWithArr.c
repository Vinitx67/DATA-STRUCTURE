#include <stdio.h>
void main()
{
    int x[5] = {10, 20, 30, 40, 50};
    int *p, i;
    p = x;

    for (i = 1; i <= 5; i++)
    {
        printf("P : %u\n", p);
        printf("*P : %d\n", *p);
        p++;
    }
}