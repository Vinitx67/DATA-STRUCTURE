#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
} *start = NULL;

void CREATE();
void INSERT_BEGIN();
void INSERT_BEFORE();
void INSERT_AFTER();
void INSERT_END();
void DELETE_BEGIN();
void DELETE_GIVEN();
void DELETE_END();
void DISP();

int menu()
{
    int choice;
    // clrscr();
    printf("\n\n 1] CREATE A CIRCULALRLY LINKED LIST");
    printf("\n 2] INSERT AT BEGINING");
    printf("\n 3] INSERT AT BEFORE");
    printf("\n 4] INSERT AT AFTER");
    printf("\n 5] INSERT AT END");
    printf("\n 6] DELETE BEGIN");
    printf("\n 7] DELETE GIVEN");
    printf("\n 8] DELETE END");
    printf("\n 9] DISPLAY A CIRCULALRLY LINKED LIST");
    printf("\n 10] EXIT");

    printf("\n\nENTER YOUR CHOICE : ");
    scanf("%d", &choice);
    return choice;
}

void main()
{
    int ch;
    // clrscr();
    do
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            CREATE();
            DISP();
            break;
        case 2:
            INSERT_BEGIN();
            DISP();
            break;
        case 3:
            INSERT_BEFORE();
            DISP();
            break;
        case 4:
            INSERT_AFTER();
            DISP();
            break;
        case 5:
            INSERT_END();
            DISP();
            break;
        case 6:
            DELETE_BEGIN();
            DISP();
            break;
        case 7:
            DELETE_GIVEN();
            DISP();
            break;
        case 8:
            DELETE_END();
            DISP();
            break;
        case 9:
            DISP();
            break;
        case 10:
            // getch();
            exit(0);
        default:
            printf("\n INVALID DOUBLY LINKED LIST");
        }
        // getch();
    } while (ch != 10);
}

void CREATE()
{
    struct node *newnode, *temp;
    newnode = malloc(sizeof(struct node));

    printf("\n ENTER A NUMBER : ");
    scanf("%d", &newnode->num);

    if (start == NULL)
    {
        start = newnode;
        start->next = start;
    }
    else
    {
        temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = start;
    }
}

void DISP()
{
    struct node *temp;

    if (start == NULL)
    {
        printf("\n NO LINKED LIST");
    }
    else
    {
        temp = start;
        do
        {
            printf("\n\n%d", temp->num);
            temp = temp->next;
        } while (temp != start);
    }
}

void INSERT_BEGIN()
{
    struct node *newnode, *temp;
    newnode = malloc(sizeof(struct node));

    printf("\n ENTER A NUMBER : ");
    scanf("%d", &newnode->num);

    newnode->next = start;
    temp = start;

    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    start = newnode;
}

void INSERT_BEFORE()
{
    int tnum;
    struct node *newnode, *temp;

    printf("\n ENTER A TARGET NUMBER :");
    scanf("%d", &tnum);

    if (tnum == start->num)
    {
        INSERT_BEGIN();
    }
    else
    {
        temp = start;
        while (temp->next != start && temp->next->num != tnum)
        {
            temp = temp->next;
        }
        if (temp->next == start)
        {
            printf("TARGET NOT FOUND");
        }
        else
        {
            newnode = malloc(sizeof(struct node));
            printf("\n ENTER A NUMBER : ");
            scanf("%d", &newnode->num);

            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}
void INSERT_AFTER()
{
    int tnum;
    struct node *newnode, *temp;

    printf("\n ENTER A TARGET NUMBER :");
    scanf("%d", &tnum);

    temp = start;

    while (temp->num != tnum && temp->next != start)
    {
        temp = temp->next;
    }
    if (temp->num != tnum && temp->next == start)
    {
        printf("NUMBER NOT FOUND");
    }
    else
    {
        newnode = malloc(sizeof(struct node));
        printf("\n ENTER A NUMBER : ");
        scanf("%d", &newnode->num);

        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void INSERT_END()
{
    struct node *newnode, *temp;

    temp = start;

    while (temp->next != start)
    {
        temp = temp->next;
    }
    newnode = malloc(sizeof(struct node));
    printf("\n ENTER A NUMBER : ");
    scanf("%d", &newnode->num);

    newnode->next = start;
    temp->next = newnode;
}

void DELETE_BEGIN()
{
    struct node *temp, *temp2;

    if (start->next == start)
    {
        free(start);
        start = NULL;
    }
    else
    {
        temp2 = start->next;
        temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = temp2;
        free(start);
        start = temp2;
    }
}

void DELETE_GIVEN()
{
    int tnum;
    struct node *temp, *temp2;

    printf("\n ENTER A NUMBER TO BE DELETED :");
    scanf("%d", &tnum);

    if (tnum == start->num)
    {
        DELETE_BEGIN();
    }
    else
    {
        temp = start;
        while (temp->next != start && temp->next->num != tnum)
        {
            temp = temp->next;
        }
        if (temp->next == start)
        {
            printf("NUMBER NOT FOUND");
        }
        else
        {
            temp2 = temp->next->next;
            free(temp->next);
            temp->next = temp2;
        }
    }
}

void DELETE_END()
{
    struct node *temp;

    if (start->next == start)
    {
        free(start);
        start = NULL;
    }
    else
    {
        temp = start;
        while (temp->next->next != start)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = start;
    }
}