#include <stdio.h>
void main()
{
    int i, j, k, m, n, A[10], B[10], C[20];

    printf("ENTER A SIZE : ");
    scanf("%d", &m);

    printf("ENTER A NUMBER IN ASC ODER: \n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("ENTER A SIZE : ");
    scanf("%d", &n);

    printf("ENTER A NUMBER IN ASC ODER: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &B[i]);
    }

    for (i = 0, j = 0, k = 0; i < m && j < n; k++)
    {
        if (A[i] < B[j])
        {
            C[k] = A[i];
            i++;
        }
        else
        {
            C[k] = B[j];
            j++;
        }
    }
    while (i < m)
    {
        C[k] = A[i];
        i++;
        k++;
    }
    while (j < n)
    {
        C[k++] = B[j++];
    }
    printf("MERGE ALGO : \n");
    for (i = 0; i < m + n; i++)
    {
        printf("%d ", C[i]);
    }
}