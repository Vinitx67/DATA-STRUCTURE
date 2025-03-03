#include <stdio.h>
void Fun2d(int[][3]);
void main()
{
    int A[3][3], i, j;
    printf("ENTER 9 NUMBERS :\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    Fun2d(A);

    printf("MATRIX TRANSPOSE :\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void Fun2d(int B[][3])
{
    int i, j, temp;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i < j)
            {
                temp = B[i][j];
                B[i][j] = B[j][i];
                B[j][i] = temp;
            }
        }
    }
}