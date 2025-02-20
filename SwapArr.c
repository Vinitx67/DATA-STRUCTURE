#include <stdio.h>
void main()
{
    int a = 10, b = 20, temp;

    printf("NUMBER BEFORE SWAP :\n");
    printf("A = %d \n", a);
    printf("B = %d \n", b);

    temp = a;
    a = b;
    b = temp;

    printf("\nNUMBER AFTER SWAP :\n");
    printf("A = %d \n", a);
    printf("B = %d \n", b);
}