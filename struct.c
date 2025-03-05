#include <stdio.h>

struct student
{
    char name[30];
    int rollno;
};
void main()
{
    struct student s;

    printf("\n\n Enter name: ");
    gets(s.name);
    printf("\n\n Enter RollNo: ");
    scanf("%d", &s.rollno);
}