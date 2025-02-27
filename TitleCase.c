#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    int capitalize = 1;

    printf("enter a string: ");
    gets(str);

    for (int i = 0; i < strlen(str); i++)
    {
        if (capitalize && str[i] != ' ')
        {
            str[i] = toupper(str[i]);
            capitalize = 0;
        }
        else
        {
            str[i] = tolower(str[i]);
        }

        if (str[i] == ' ')
        {
            capitalize = 1;
        }
    }

    printf("\ncapitalized string: %s\n", str);
    return 0;
}
