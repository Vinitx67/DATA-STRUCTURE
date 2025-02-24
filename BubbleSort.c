#include <stdio.h>
void main()
{
    int size, x[50], i, j, temp;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER A NUMBER : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (x[j] > x[j + 1])
            {
                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
        printf("\nBUBBLE SORT : \n");
        for (j = 0; j < size; j++)
        {
            printf("%d ", x[j]);
        }
    }
}