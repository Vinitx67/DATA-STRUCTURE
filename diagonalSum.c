#include <stdio.h>
void main()
{
    int A[3][3], bd = 0, fd = 0, i, j;

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
        for (j = 0; j < 3; j++)
        {
            if (i == j)
            {
                fd = fd + A[i][j];
            }
            if (i + j == 2)
            {
                bd = bd + A[i][j];
            }
        }
    }

    // for (i = 0; i < 3; i++)
    // {
    //     fd = fd + A[i][i];
    //     bd = bd + A[i][2 - i];
    // }

    printf("SUM OF FORWARD DIAGONAL : %d\n", fd);
    printf("SUM OF BACKWARD DIAGONAL : %d\n", bd);
}