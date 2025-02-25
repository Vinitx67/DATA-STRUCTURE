#include <stdio.h>
#include <string.h>
void main()
{
    char str1[30], str2[30];

    printf("ENTER A STRING : ");
    gets(str1);

    strcpy(str2, str1);
    printf("STRING AFTER COPY : %s ", str2);
}