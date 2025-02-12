#include <stdio.h>
#include <conio.h>

union abc
{
    int a;
    int b;
};
void main()
{
    union abc obj;

    clrscr();

    obj.a = 10;
    obj.b = 20;
}