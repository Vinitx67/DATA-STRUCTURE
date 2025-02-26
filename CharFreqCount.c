// Write a program that takes a string as input and counts the occurrences of each character in the string, ignoring duplicate counts. The program should display the frequency of each unique character.

#include <stdio.h>
#include <string.h>
void main()
{
    char str[30];
    int i, j, count;

    printf("ENTER A STRINNG : ");
    gets(str);

    for (i = 0; i < strlen(str); i++)
    {
        count = 1;
        for (j = i + 1; j < strlen(str); j++)
        {
            if (str[i] == str[j])
            {
                count++;
                str[j] = '*';
            }
        }
        if (str[i] != '*')
        {
            printf("%c : %d\n", str[i], count);
        }
    }
}