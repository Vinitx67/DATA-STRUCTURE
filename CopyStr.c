#include <stdio.h>
void main()
{
    char str1[30], str2[30];
    int i;

    printf("ENTER A STRINNG : ");
    gets(str1);

    for (i = 0; str1[i] != '\0'; i++)
    {
        str2[i] = str1[i];
    }
    str2[i] = '\0';
    printf("STRING AFTER COPY : %s", str2);
}