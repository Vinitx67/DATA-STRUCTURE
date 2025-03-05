#include <stdio.h>
struct student
{
    char name[30];
    int rollNo;
    int marks;
};
void main()
{
    struct student s[3];
    int i;

    for (i = 0; i < 3; i++)
    {
        fflush(stdin);

        printf("\nENTER A NAME : ");
        gets(s[i].name);

        printf("ENTER A ROLL NO : ");
        scanf("%d", &s[i].rollNo);

        printf("ENTER A MARKS : ");
        scanf("%d", &s[i].marks);
    }

    for (i = 0; i < 3; i++)
    {
        if (s[i].marks >= 100)
        {
            printf("\nNAME : %s\n", s[i].name);
            printf("ROLL NO : %d\n", s[i].rollNo);
            printf("MARKS : %d\n", s[i].marks);
        }
    }
}