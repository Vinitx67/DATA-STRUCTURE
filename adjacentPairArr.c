// Write a C program that takes an array of integers from the user and swaps every adjacent pair of elements.

#include <stdio.h>
void main()
{
    int size, x[50], i, temp;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER A NUMBER : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    for (i = 0; i < size; i = i + 2)
    {
        temp = x[i];
        x[i] = x[i + 1];
        x[i + 1] = temp;
    }

    printf("LIST AFTER REVERSING : \n");
    for (i = 0; i < size; i++)
    {
        printf("%d\n", x[i]);
    }
}