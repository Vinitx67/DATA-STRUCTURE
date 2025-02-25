#include <stdio.h>
#include <string.h>
void main()
{
    char str[30], temp[30];

    printf("ENTER A STRING : ");
    gets(str);

    strcpy(temp, str);

    strrev(str);

    if (strcmp(str, temp) == 0)
    {
        printf("STRING IS PALINDROME");
    }
    else
    {
        printf("STRING IS NOT PALINDROME");
    }
}