#include <stdio.h>
void main()
{
    int size, x[50], i, max, min;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER A NUMBER : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    min = max = x[0];
    for (i = 0; i < size; i++)
    {
        if (min > x[i])
        {
            min = x[i];
        }
        if (max < x[i])
        {
            max = x[i];
        }
    }
    printf("MIN IS : %d \n", min);
    printf("MAX IS : %d", max);
}