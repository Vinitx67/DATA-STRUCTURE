#include <stdio.h>
void main()
{
    int A[10][10], i, j, sum = 0;

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
        for (j = 0; j < 4; j++)
        {
            if (i == 0 || j == 0 || i == 3 || j == 3)
            {
                sum = sum + A[i][j];
            }
        }
    }
    printf("SUM OF BORDER ELEMENTS: %d", sum);
}