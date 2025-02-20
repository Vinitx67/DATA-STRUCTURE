#include <stdio.h>
void main()
{
    int size, x[50], i, j, temp;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER A NUMBER : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (x[i] > x[j])
            {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
    printf("LIST AFTER SORTING : \n");
    for (i = 0; i < size; i++)
    {
        printf("%d\n", x[i]);
    }
}