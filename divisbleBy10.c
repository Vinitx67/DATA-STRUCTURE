#include <stdio.h>
void main()
{
    int size, x[50], i, temp;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER A NUMBER : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    for (i = 0; i < size - 1; i++)
    {
        if (x[i] % 10 == 0)
        {
            temp = x[i];
            x[i] = x[i + 1];
            x[i + 1] = temp;
            i++;
        }
    }

    printf("LIST : \n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", x[i]);
    }
}