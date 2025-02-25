#include <stdio.h>
#include <string.h>

void main()
{
    char str[30];
    int i;

    printf("ENTER A STRING : ");
    gets(str);

    i = strlen(str);
    printf("STRING LENGTH : %d", i);
}