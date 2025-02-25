#include <stdio.h>
#include <string.h>
void main()
{
    char str[30];
    int i, count = 0;

    printf("ENTER A STRING : ");
    gets(str);

    for (i = 0; i < strlen(str); i++)
    {
        switch (str[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            count++;
        }
    }
    printf("COUNT : %d", count);
}