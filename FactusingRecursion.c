#include <stdio.h>
int factorial(int);
void main()
{
    int num, ans;
    printf("ENTER A NUMBER : ");
    scanf("%d", &num);

    ans = factorial(num);

    printf("FACTORIAL IS : %d", ans);
}

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}