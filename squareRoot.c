// SQUARE ROOT USING FOR LOOP

#include <stdio.h>
void main()
{
    int n, i, ans;

    printf("ENTER A NUMBER : ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        if (i * i == n)
        {
            ans = i;
            break;
        }
    }
    printf("SQUARE ROOT IS : %d ", ans);
}