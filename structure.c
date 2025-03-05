#include <stdio.h>
struct student
{
    char name[30];
    int rollNo;
};
void main()
{
    struct student s;

    printf("\nENTER A NAME : ");
    gets(s.name);

    printf("ENTER A ROLL NO : ");
    scanf("%d", &s.rollNo);

    printf("\nNAME : %s\n", s.name);
    printf("ROLL NO : %d\n", s.rollNo);
}