#include <stdio.h>
void main()
{
    int size, x[50], i, num, pos;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);
    pos = size;

    printf("ENTER A NUMBER (MUST BE IN ASCENDING): \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    printf("ENTER A NUM TO BE INSERTED : ");
    scanf("%d", &num);

    for (i = 0; i < size; i++)
    {
        if (num < x[i])
        {
            pos = i;
            break;
        }
    }
    for (i = size; i > pos; i--)
    {
        x[i] = x[i - 1];
    }
    x[pos] = num;

    printf("LIST AFTER INSERTION : \n");
    for (i = 0; i <= size; i++)
    {
        printf("%d\n", x[i]);
    }
}