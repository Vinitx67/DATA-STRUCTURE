#include <stdio.h>
void main()
{
    int size, x[50], i, num, pos = -1;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER A NUMBER : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    printf("ENTER A NUM TO BE DELETED : ");
    scanf("%d", &num);

    for (i = 0; i < size; i++)
    {
        if (num == x[i])
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        printf("NUMBER NOT FOUND");
    }
    else
    {
        x[pos] = 0;
        for (i = pos; i < size - 1; i++)
        {
            x[i] = x[i + 1];
        }
    }
    printf("LIST AFTER DELETION : \n");
    for (i = 0; i < size - 1; i++)
    {
        printf("%d\n", x[i]);
    }
}