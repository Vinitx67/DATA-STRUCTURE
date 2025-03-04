#include <stdio.h>
void main()
{
    int x[5] = {10, 20, 30, 40, 50};
    int *p, **q, *t;
    p = x;
    q = &t;
    t = x + 1;

    printf("%d %d %d", *p, **q, *t++);
}