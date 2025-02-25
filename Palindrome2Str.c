#include <stdio.h>
#include <string.h>
void main()
{
    char str[30];
    int i, j, len, flag = 1;

    printf("ENTER A STRING : ");
    gets(str);

    len = strlen(str);

    for (i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        if (str[i] != str[j])
        {
            flag = 2;
            break;
        }
    }
    if (flag == 1)
    {
        printf("STRING IS PALINDROME");
    }
    else
    {
        printf("STRING IS NOT PALINDROME");
    }
}