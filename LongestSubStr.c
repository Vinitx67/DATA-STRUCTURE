#include <stdio.h>
#include <string.h>

void main()
{
    char str[100], word[100], longest[100] = "";
    int i, j, len, max = 0;

    printf("ENTER A STRING: ");
    gets(str);

    for (i = 0; i < strlen(str); i++)
    {
        j = 0;
        while (str[i] != ' ' && str[i] != '\0')
        {
            word[j] = str[i];
            i++;
            j++;
        }
        word[j] = '\0';

        if (max < strlen(word))
        {
            max = strlen(word);
            strcpy(longest, word);
        }
        else if (max == strlen(word))
        {
            strcat(longest, ", ");
            strcat(longest, word);
        }
    }
    printf("\n LONGEST STRING : %s", longest);
    printf("\n LENGTH : %d", max);
}