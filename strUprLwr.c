#include <stdio.h>
#include <string.h>

void main()
{
    char str[30];

    printf("ENTER A STRING : ");
    gets(str);

    strupr(str);
    printf("STRING IN UPPERCASE : %s\n", str);

    strlwr(str);
    printf("STRING IN LOWERCASE : %s", str);
}