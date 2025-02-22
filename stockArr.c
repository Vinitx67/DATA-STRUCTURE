// Write a C program that takes an array representing stock prices on different days and finds the maximum possible profit by choosing a day to buy and a later day to sell.The program should output the maximum profit along with the corresponding buy and sell prices.

#include <stdio.h>
void main()
{
    int x[] = {7, 1, 5, 3, 6, 4}, buy, sell;
    int i, j, size = 6, max = 0, profit;

    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            profit = x[j] - x[i];
            if (max < profit)
            {
                max = profit;
                buy = x[i];
                sell = x[j];
            }
        }
    }
    printf("PROFIT : %d\n", max);
    printf("BUY : %d\n", buy);
    printf("SELL : %d", sell);
}