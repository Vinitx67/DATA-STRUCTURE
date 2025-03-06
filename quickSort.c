#include <stdio.h>
void QUICK(int[], int, int);
void main()
{
    int x[30], size, i;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER A NUMBER : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    QUICK(x, 0, size - 1);

    printf("\nLIST AFTER SORTING : \n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", x[i]);
    }
}

void QUICK(int x[], int f, int l)
{
    int i, j, pivot, temp;

    if (f < l)
    {
        pivot = i = f;
        j = l;

        while (i < j)
        {
            while (x[i] <= x[pivot] && i < l)
            {
                i++;
            }

            while (x[j] > x[pivot] && j > 0)
            {
                j--;
            }

            if (i < j)
            {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }

        temp = x[pivot];
        x[pivot] = x[j];
        x[j] = temp;

        QUICK(x, f, j - 1);
        QUICK(x, j + 1, l);
    }
}
