#include <stdio.h>
void main()
{
    int size, x[50], i, j, temp, small, pos;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER A NUMBER : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    for (i = 0; i < size; i++)
    {
        small = x[i];
        pos = i;
        for (j = i + 1; j < size; j++)
        {
            if (small > x[j])
            {
                small = x[j];
                pos = j;
            }
        }
        temp = x[i];
        x[i] = x[pos];
        x[pos] = temp;

        printf("\nSELECTION SORT : \n");
        for (j = 0; j < size; j++)
        {
            printf("%d ", x[j]);
        }
    }
}