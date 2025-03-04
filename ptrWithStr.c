#include <stdio.h>
void main()
{
    char str[30] = "computer";

    char *p;
    int i;
    p = str;

    for (i = 1; i <= 8; i++)
    {
        printf("P : %s\n", p);
        printf("*P : %c\n\n", *p);
        p++;
    }
}