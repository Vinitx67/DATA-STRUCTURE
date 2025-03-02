#include <stdio.h>
#include <string.h>

void main()
{
    char str[3][20], temp[30];
    int i, j;

    printf("ENTER A STRING: \n");
    for (i = 0; i < 3; i++)
    {
        gets(str[i]);
    }
    for (i = 0; i < 3; i++)
    {
        for (j = i + 1; j < 3; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
    printf("SORTED STRINGS :\n");
    for (i = 0; i < 3; i++)
    {
        puts(str[i]);
    }
}