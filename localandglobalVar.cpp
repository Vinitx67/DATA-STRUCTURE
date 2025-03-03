#include <stdio.h>
int G = 100;
int main()
{
    int G = 50;
    printf("LOCAL : %d\n", G);
    printf("GLOBAL : %d", ::G);
}