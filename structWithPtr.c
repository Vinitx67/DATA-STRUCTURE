#include <stdio.h>
struct student
{
    char name[30];
    int rollNo;
};

void main()
{
    struct student s;
    struct student *p;

    p = &s;

    printf("ENTER A NAME : ");
    gets(p->name);

    printf("ENTER A ROLL NO : ");
    scanf("%d", &p->rollNo);

    printf("\nNAME : %s\n", p->name);
    printf("ROLL NO : %d", p->rollNo);
}