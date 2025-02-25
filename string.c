#include <stdio.h>
void main()
{
    char str[20] = "computer";
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        printf("STRING : %c\n", str[i]);
    }
}