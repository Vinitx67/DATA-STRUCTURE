#include <stdio.h>
int sum(int);
void main()
{
    int num, ans;
    printf("ENTER A NUMBER : ");
    scanf("%d", &num);

    ans = sum(num);

    printf("SUM OF N NUMBER IS : %d", ans);
}

int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sum(n - 1);
}