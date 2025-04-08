#include <stdio.h>
int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}
int main()
{
    int num = 5;
    printf("THE 5th TERM IN FIBONACCI SERIES IS %d", fibo(num));
}