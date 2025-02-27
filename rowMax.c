#include <stdio.h>
void main()
{
    int A[3][3], i, j, max;

    printf("ENTER 9 NUMBERS : \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for (i = 0; i < 3; i++)
    {
        max = A[i][0];
        for (j = 1; j < 3; j++)
        {
            if (A[i][j] > max)
            {
                max = A[i][j];
            }
        }
        printf("MAX : %d\n", max);
    }
}