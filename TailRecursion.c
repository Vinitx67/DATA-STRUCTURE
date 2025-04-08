#include <stdio.h>
void count(int num)
{
    if (num > 10)
    {
        return;
    }
    printf("%d, ", num);
    count(num + 1);
}
int main()
{
    // TAIL recursion
    count(1);
}