#include <stdio.h>
#include <string.h>

void main()
{
    char str[30];

    printf("ENTER A STRING : ");
    gets(str);

    strrev(str);
    printf("STRING AFTER REVERSING : %s", str);
}