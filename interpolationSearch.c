#include <stdio.h>
void main()
{
    int size, x[50], i, num, pos = 0;
    int beg, mid, end;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER A NUMBER: \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    printf("ENTER A NUM TO BE SEARCHED : ");
    scanf("%d", &num);

    beg = 0, end = size - 1;

    while (beg <= end)
    {
        mid = beg + (end - beg) * ((num - x[beg]) / (x[end] - x[beg]));
        if (num == x[mid])
        {
            pos = mid + 1;
            break;
        }
        else if (num < x[mid])
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
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