#include <stdio.h>
void main()
{
    int size, x[50], i, num, pos = 0;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER A NUMBER : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    printf("ENTER A NUM TO BE SEARCHED : ");
    scanf("%d", &num);

    for (i = 0; i < size; i++)
    {
        if (num == x[i])
        {
            pos = i + 1;
            break;
        }
    }
    if (pos == 0)
    {
        printf("NUMBER NOT FOUND");
    }
    else
    {
        printf("PSITION IS : %d", pos);
    }
}