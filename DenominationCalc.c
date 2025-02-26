// Write a program that takes an amount in rupees and determines the minimum number of currency notes/coins needed to make that amount, using denominations of 500, 200, 100, 50, 20, 10, 5, 2, and 1.

#include <stdio.h>
#include <string.h>
void main()
{
    int demo[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int size = 9, i, amount;

    printf("ENTER A NUMBER : ");
    scanf("%d", &amount);

    for (i = 0; i < size; i++)
    {
        if (amount >= demo[i])
        {
            printf("%d : %d\n", demo[i], amount / demo[i]);
            amount = amount % demo[i];
        }
    }
}