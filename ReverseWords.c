#include <stdio.h>
#include <string.h>
void main()
{
    char str[100], word[100];
    int i, j;

    printf("ENTER A STRINNG : ");
    gets(str);

    for (i = 0; i < strlen(str); i++)
    {
        j = 0;
        while (str[i] != ' ' && str[i] != '\0')
        {
            word[j] = str[i];
            j++;
            i++;
        }
        word[j] = '\0';
        printf("%s ", strrev(word));
    }
}