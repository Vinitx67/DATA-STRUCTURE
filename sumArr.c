// Write a C program to find the sum of an array of integers entered by the user

#include <stdio.h>
void main()
{
    int size, x[50], i, sum = 0;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER A NUMBER : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
        sum = sum + x[i];
    }
    printf("SUM IS : %d ", sum);
}