#include <stdio.h>
int reverse(int);
void main()
{
    int num, ans;
    printf("ENTER A NUMBER : ");
    scanf("%d", &num);

    ans = reverse(num);
    printf("REVERSE ORDER IS : %d", ans);
}

int rem, rev = 0;

int reverse(int n)
{
    if (n != 0)
    {
        rem = n % 10;
        rev = (rev * 10) + rem;
        reverse(n / 10);
    }
    return rev;
}