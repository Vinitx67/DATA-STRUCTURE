// Write a C program that takes an array of integers from the user and rotates the elements to the right by one position

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

    temp = x[size - 1];
    for (i = size - 1; i > 0; i--)
    {
        x[i] = x[i - 1];
    }
    x[0] = temp;

    printf("LIST AFTER ROTATING : \n");
    for (i = 0; i < size; i++)
    {
        printf("%d\n", x[i]);
    }
}