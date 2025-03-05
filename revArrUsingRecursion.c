#include <stdio.h>
void reverse(int[], int, int);
void main()
{
    int x[30], i, size;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER A NUMBER : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    reverse(x, 0, size - 1);

    printf("LIST AFTER REVERSE : \n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", x[i]);
    }
}

void reverse(int x[], int i, int j)
{
    int temp;
    if (i < j)
    {
        temp = x[i];
        x[i] = x[j];
        x[j] = temp;
        reverse(x, i + 1, j - 1);
    }
}