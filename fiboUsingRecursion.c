#include <stdio.h>
int fibo(int);
void main()
{
    int n, i;
    printf("ENTER A NUMBER : ");
    scanf("%d", &n);

    printf("FIBONACCI SERIES IS : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", fibo(i));
    }
}

int fibo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);
}