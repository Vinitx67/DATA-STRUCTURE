#include <stdio.h>
int nested(int x)
{
    if (x > 2)
    {
        return x;
    }
    return nested(nested(x + 1));
}
int main()
{
    // nested recursion
    printf("%d", nested(0));
}