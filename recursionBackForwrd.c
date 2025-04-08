#include <stdio.h>
void count(int num)
{
    if (num > 10)
    {
        return;
    }
    printf("%d, ", num);
    count(num + 1);
    printf("%d, ", num);
}
int main()
{
    count(1);
}