#include <stdio.h>
void main()
{
    int x[30], size, i, j, temp;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER A NUMBER : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    for (i = 1; i < size; i++)
    {
        temp = x[i];
        j = i - 1;

        while (j >= 0 && x[j] > temp)
        {
            x[j + 1] = x[j];
            j--;
        }
        x[j + 1] = temp;
        printf("\nSORTED LIST : \n");
        for (j = 0; j < size; j++)
        {
            printf("%d ", x[j]);
        }
    }
}