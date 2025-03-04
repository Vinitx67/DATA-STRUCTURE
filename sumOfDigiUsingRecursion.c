#include <stdio.h>
int sumOfDigits(int);
void main()
{
    int num, ans;
    printf("ENTER A NUMBER : ");
    scanf("%d", &num);

    ans = sumOfDigits(num);
    printf("SUM OF DIGITS IS : %d", ans);
}

int rem, sum = 0;
int sumOfDigits(int n)
{
    if (n != 0)
    {
        rem = n % 10;
        sum = sum + rem;
        sumOfDigits(n / 10);
    }
    return sum;
}