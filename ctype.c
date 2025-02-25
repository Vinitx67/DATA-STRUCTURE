#include <stdio.h>
#include <string.h>
#include <ctype.h>
void main()
{
    char str[30];
    int i;

    printf("ENTER A STRING : ");
    gets(str);

    for (i = 0; i < strlen(str); i++)
    {
        if (islower(str[i]))
        {
            str[i] = toupper(str[i]);
        }
        else if (isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }
    }
    printf("STR : %s", str);
}