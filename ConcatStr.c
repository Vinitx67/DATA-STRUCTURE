#include <stdio.h>
void main()
{
    char str1[30], str2[30];
    int i, len = 0;

    printf("ENTER A STRINNG : ");
    gets(str1);

    printf("ENTER A STRINNG : ");
    gets(str2);

    for (i = 0; str1[i] != '\0'; i++)
    {
        len++;
    }

    for (i = 0; str2[i] != '\0'; i++)
    {
        str1[len + i] = str2[i];
    }
    str1[len + i] = '\0';

    printf("STRING AFTER CONCAT : %s", str1);
}