#include <stdio.h>
#include <string.h>
void main()
{
    char str[40], temp;
    int i, j;

    printf("ENTER A STRING : ");
    gets(str);

    for (i = 0; i < strlen(str); i++)
    {
        for (j = i + 1; j < strlen(str); j++)
        {
            if (str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    printf("SORTED ARRAY : %s", str);
}