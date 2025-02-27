#include <stdio.h>
void main()
{
    int A[3][3], i, j;

    printf("ENTER 9 NUMBERS : \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("LOWER TRIANGLE : \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i >= j)
            {
                printf("%d ", A[i][j]);
            }
        }
        printf("\n");
    }

    printf("UPPER TRIANGLE : \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i <= j)
            {
                printf("%d ", A[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}