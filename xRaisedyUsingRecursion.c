#include <stdio.h>
int power(int, int);
void main()
{
    int x, y, ans;

    printf("ENTER X : ");
    scanf("%d", &x);

    printf("ENTER Y : ");
    scanf("%d", &y);

    ans = power(x, y);
    printf("ANSWER IS : %d", ans);
}

int power(int x, int y)
{
    if (y == 1)
    {
        return x;
    }
    return x * power(x, y - 1);
}