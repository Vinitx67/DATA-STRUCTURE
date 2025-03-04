#include <stdio.h>
void main()
{
    int x = 100;
    int *p, **q;

    p = &x;

    printf("P : %u\n", p);
    printf("*P : %d\n", *p);

    *p = 123;

    printf("X : %d\n", x);

    q = &p;
    printf("q : %u\n", q);
    printf("*q : %u\n", *q);
    printf("**q : %d\n", **q);
}