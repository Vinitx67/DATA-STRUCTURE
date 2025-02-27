#include <stdio.h>
void main()
{
    int A[3][3], i, j, sum = 0;

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
        sum = 0;
        for (j = 0; j < 3; j++)
        {
            sum = sum + A[i][j];
        }
        printf("SUM : %d\n", sum);
    }
}