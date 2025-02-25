#include <stdio.h>
#include <string.h>
void main()
{
    char str1[30], str2[30];
    int i;

    printf("ENTER A STRING : ");
    gets(str1);

    printf("ENTER A STRING : ");
    gets(str2);

    i = strcmp(str1, str2);
    // i = strcmpi(str1, str2);

    printf("i = %d\n", i);
    if (i == 0)
    {
        printf("SAME STRING");
    }
    else
    {
        printf("NOT A SAME STRING");
    }
}