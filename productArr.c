// Write a C program that takes an array of integers from the user and replaces each element with the product of all other elements in the array

#include <stdio.h>
void main()
{
    int size, x[50], i, prod = 1;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER A NUMBER : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    for (i = 0; i < size; i++)
    {
        prod = prod * x[i];
    }

    printf("PRODUCT IS : \n");
    for (i = 0; i < size; i++)
    {
        x[i] = prod / x[i];
        printf("%d\n", x[i]);
    }
}