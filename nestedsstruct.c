#include <stdio.h>
// #include <conio.h>

struct marks
{
    int p, c, m;
};
struct student
{
    char name[30];
    int rollno;

    struct marks m;
};
void main()
{
    struct student s;
    int total;

    // clrscr();

    printf("\n\n Enter name: ");
    gets(s.name);
    printf("\n\n Enter RollNo: ");
    scanf("%d", &s.rollno);

    printf("\n\n Enter marks of 3 subjects: ");
    scanf("%d%d%d", &s.m.p, &s.m.c, &s.m.m);

    total = s.m.p + s.m.c + s.m.m;
    printf("\n\n total marks = %d", total);

    // getch();
}