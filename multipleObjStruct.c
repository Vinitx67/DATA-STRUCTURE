#include <stdio.h>
struct time
{
    int hr, min;
};
void main()
{
    struct time t1, t2, t3;

    printf("ENTER TIME FOR FIRST OBJECT : \n");
    printf("ENTER HOUR : ");
    scanf("%d", &t1.hr);
    printf("ENTER MINUTE : ");
    scanf("%d", &t1.min);

    printf("\nENTER TIME FOR SECOND OBJECT : \n");
    printf("ENTER HOUR : ");
    scanf("%d", &t2.hr);
    printf("ENTER MINUTE : ");
    scanf("%d", &t2.min);

    t3.hr = t1.hr + t2.hr;
    t3.min = t1.min + t2.min;

    if (t3.min >= 60)
    {
        t3.hr = t3.hr + (t3.min / 60);
        t3.min = t3.min % 60;
    }

    printf("\nTOTAL TIME : \n");
    printf("HOUR : %d\n", t3.hr);
    printf("MINUTE : %d", t3.min);
}