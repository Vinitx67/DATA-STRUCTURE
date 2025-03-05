#include <stdio.h>
struct student
{
    char name[30];
    int rollNo;
    int marks;
};
void main()
{
    struct student s[3], temp;
    int i, j;

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
        for (j = 0; j < 2; j++)
        {
            if (s[j].marks > s[j + 1].marks)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\nSORTED OBJECTS : \n");
    for (i = 0; i < 3; i++)
    {
        printf("\nNAME : %s\n", s[i].name);
        printf("ROLL NO : %d\n", s[i].rollNo);
        printf("MARKS : %d\n", s[i].marks);
    }
}