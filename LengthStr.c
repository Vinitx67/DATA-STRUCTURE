#include <stdio.h>
void main()
{
    char str[30];
    int i, len = 0;

    printf("ENTER A STRINNG : ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++)
    {
        len++;
    }
    printf("LENGTH : %d", len);
}