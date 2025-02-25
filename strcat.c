#include <stdio.h>
#include <string.h>
void main()
{
    char str1[30], str2[30];

    printf("ENTER A STRING : ");
    gets(str1);

    printf("ENTER A STRING : ");
    gets(str2);

    strcat(str1, str2);
    printf("STRING 1 : %s\n", str1);
    printf("STRING 2 : %s", str2);
}