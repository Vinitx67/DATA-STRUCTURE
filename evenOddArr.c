#include <stdio.h>

void main()
{
    int x[] = {10, 11, 12, 13, 14};
    int even[5], odd[5]; // Arrays to store even and odd numbers
    int i, eCount = 0, oCount = 0;
    int size = sizeof(x) / sizeof(x[0]);

    // Separating even and odd numbers
    for (i = 0; i < size; i++)
    {
        if (x[i] % 2 == 0)
        {
            even[eCount++] = x[i];
        }
        else
        {
            odd[oCount++] = x[i];
        }
    }

    // Printing even numbers
    printf("Even numbers: ");
    for (i = 0; i < eCount; i++)
    {
        printf("%d ", even[i]);
    }
    printf("\n");

    // Printing odd numbers
    printf("Odd numbers: ");
    for (i = 0; i < oCount; i++)
    {
        printf("%d ", odd[i]);
    }
    printf("\n");
}
