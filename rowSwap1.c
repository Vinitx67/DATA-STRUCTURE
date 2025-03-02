#include <stdio.h>
void main()
{
    int A[10][10], i, j, temp;

    printf("ENTER 16 NUMBERS : \n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for (i = 0; i < 4; i++)
    {
        temp = A[i][0];
        A[i][0] = A[i][3];
        A[i][3] = temp;
    }

    printf("SWAPPED MATRIX:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}