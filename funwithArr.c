#include <stdio.h>
void SORT(int[], int);
void main()
{
    int size, x[40], i;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER NUMBERS : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }
    SORT(x, size);

    printf("LIST AFTER SORTING : ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", x[i]);
    }
}

void SORT(int y[], int size)
{
    int i, j, temp;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (y[j] > y[j + 1])
            {
                temp = y[j];
                y[j] = y[j + 1];
                y[j + 1] = temp;
            }
        }
    }
}