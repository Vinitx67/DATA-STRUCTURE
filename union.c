#include <stdio.h>

union abc
{
    int a, b;
};
void main()
{
    union abc obj;

    obj.a = 10;
    obj.b = 20;

    printf("A: %d\n", obj.a);
    printf("B: %d\n", obj.b);
}