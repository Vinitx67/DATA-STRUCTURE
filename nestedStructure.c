#include <stdio.h>
struct marks
{
    int p, c, m;
};

struct student
{
    char name[30];
    int rollNo;

    struct marks m;
};
void main()
{
    struct student s;
    int total;

    printf("ENTER A NAME : ");
    gets(s.name);

    printf("ENTER A ROLL NO : ");
    scanf("%d", &s.rollNo);

    printf("ENTER A MARKS FOR 3 SUBJECTS : \n");
    scanf("%d%d%d", &s.m.p, &s.m.c, &s.m.m);

    total = s.m.p + s.m.c + s.m.m;
    printf("TOTAL MARKS : %d", total);
}