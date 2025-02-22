// Write a C program that takes an array of integers from the user and checks whether the array is sorted in ascending order, descending order, or not sorted at all.

#include <stdio.h>
void main()
{
    int size, x[50], i, c1 = 0, c2 = 0;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER A NUMBER : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    for (i = 0; i < size - 1; i++)
    {
        if (x[i] <= x[i + 1])
        {
            c1++;
        }
        if (x[i] >= x[i + 1])
        {
            c2++;
        }
    }

    if (c1 == size - 1)
    {
        printf("ASCENDING ORDER \n");
    }
    else if (c2 == size - 1)
    {
        printf("DESCENDING ORDER \n");
    }
    else
    {
        printf("NOT IN ORDER \n");
    }
}