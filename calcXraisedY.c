// WAP TO CALCULATE X RAISED TO Y

#include <stdio.h>
void main()
{
    int x, y, i, ans = 1;

    printf("ENTER X : ");
    scanf("%d", &x);

    printf("ENTER Y : ");
    scanf("%d", &y);

    for (i = 1; i <= y; i++)
    {
        ans = ans * x;
    }
    printf("\n ANSWER IS : %d ", ans);
}