#include <stdio.h>
struct time
{
    int hr, min;
};

struct time SUM(struct time, struct time);

void main()
{
    struct time t1, t2, t3;

    printf("ENTER TIME FOR FIRST OBJECT : \n");
    printf("ENTER HOUR : ");
    scanf("%d", &t1.hr);
    printf("ENTER MINUTE : ");
    scanf("%d", &t1.min);

    printf("\nENTER TIME FOR FIRST OBJECT : \n");
    printf("ENTER HOUR : ");
    scanf("%d", &t2.hr);
    printf("ENTER MINUTE : ");
    scanf("%d", &t2.min);

    t3 = SUM(t1, t2);
    printf("\nTOTAL TIME : \n");
    printf("HOUR : %d\n", t3.hr);
    printf("MINUTE : %d\n", t3.min);
}

struct time SUM(struct time obj1, struct time obj2)
{
    struct time obj3;

    obj3.hr = obj1.hr + obj2.hr;
    obj3.min = obj1.min + obj2.min;

    if (obj3.min >= 60)
    {
        obj3.hr = obj3.hr + (obj3.min / 60);
        obj3.min = obj3.min % 60;
    }
    return obj3;
}
