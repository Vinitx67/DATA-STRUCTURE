#include <stdio.h>
#include <string.h>

void main()
{
    char str[50], temp;
    int i, j, len;

    printf("ENTER A STRING: ");
    gets(str);

    len = strlen(str);

    for (i = 0, j = len - 1; i < len / 2;)
    {
        if (str[i] == ' ')
        {
            i++;
        }
        else if (str[j] == ' ')
        {
            j--;
        }
        else
        {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
        }
    }
    printf("\nZYCUSED STRING: %s\n", str);
}