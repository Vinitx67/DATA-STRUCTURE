#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{
    char str[30];
    int i;

    printf("ENTER A STRING: ");
    gets(str);

    str[0] = toupper(str[0]);
    for (i = 1; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            str[i + 1] = toupper(str[i + 1]);
        }
    }
    printf("\nCAPITALIZED STRING: %s\n", str);
}
