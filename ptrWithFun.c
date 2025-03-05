#include <stdio.h>
void swap(int *, int *);
void main()
{
    int a = 10, b = 20;

    printf("VALUES BEFORE SWAP : \n");
    printf("A: %d\n", a);
    printf("B: %d\n", b);

    swap(&a, &b);

    printf("\nVALUES AFTER SWAP : \n");
    printf("A: %d\n", a);
    printf("B: %d\n", b);
}

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}