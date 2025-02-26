#include <stdio.h>
void main()
{
    char str[30], temp;
    int i, j, len = 0;

    printf("ENTER A STRINNG : ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++)
    {
        len++;
    }

    for (i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    printf("STRING AFTER REVERSE : %s", str);
}