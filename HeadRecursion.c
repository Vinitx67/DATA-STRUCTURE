#include <stdio.h>
void count(int num)
{
    if (num > 10)
    {
        return;
    }
    count(num + 1);
    printf("%d, ", num);
}
int main()
{
    // head recursion
    count(1);
}