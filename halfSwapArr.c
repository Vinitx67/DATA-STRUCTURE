// The program takes an array of integers from the user and attempts to swap the first half of the array with the second half.

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

    for (i = 0; i < size / 2; i++)
    {
        temp = x[i];
        x[i] = x[size / 2 + i];
        x[size / 2 + i] = temp;
    }

    printf("LIST AFTER REVERSING : \n");
    for (i = 0; i < size; i++)
    {
        printf("%d\n", x[i]);
    }
}