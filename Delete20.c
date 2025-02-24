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
        if (x[i] == 20)
        {
            x[i] = 0;
        }
    }

    printf("\nLIST AFTER REPLACING 20 WITH 0:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", x[i]);
    }

    for (i = 0; i < size; i++)
    {
        for (j = 1; j < size; j++)
        {
            if (x[j] == 0)
            {
                x[j] = x[j - 1];
                x[j - 1] = 0;
            }
        }
    }
    printf("\nLIST AFTER SHIFTING ZEROS LEFT:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", x[i]);
    }
}