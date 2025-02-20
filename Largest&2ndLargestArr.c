#include <stdio.h>
void main()
{
    int size, x[50], i, max, max2;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER A NUMBER : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    max = 0;
    for (i = 0; i < size; i++)
    {
        if (max < x[i])
        {
            max = x[i];
        }
    }
    max2 = 0;
    for (i = 0; i < size; i++)
    {
        if (max2 < x[i] && x[i] != max)
        {
            max2 = x[i];
        }
    }
    printf("MAX IS : %d \n", max);
    printf("MAX2 IS : %d ", max2);
}