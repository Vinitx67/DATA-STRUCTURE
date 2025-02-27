#include <stdio.h>
void main()
{
    int A[3][3], B[3][3], i, j;

    printf("ENTER 9 NUMBERS : \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("MATRIX TRANSPOSE : \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            B[i][j] = A[j][i];
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
}