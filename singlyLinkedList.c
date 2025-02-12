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
void INSERT_NTH_POS();
void DELETE_BEGIN();
void DELETE_GIVEN();
void DELETE_END();
void DELETE_SECOND_LAST();
void DISP();

int menu()
{
    int choice;
    // clrscr();
    printf("\n\n 1] CREATE A LINKED LIST");
    printf("\n 2] INSERT AT BEGINING");
    printf("\n 3] INSERT AT BEFORE");
    printf("\n 4] INSERT AFTER");
    printf("\n 5] INSERT AT END");
    printf("\n 6] INSERT AT NTH POSITION");
    printf("\n 7] DELETE AT BEGIN");
    printf("\n 8] DELETE AT GIVEN");
    printf("\n 9] DELETE AT END");
    printf("\n 10] DELETE 2ND LAST");
    printf("\n 11] DISPLAY A LINKED LIST");
    printf("\n 12] EXIT");

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
            INSERT_NTH_POS();
            DISP();
            break;
        case 7:
            DELETE_BEGIN();
            DISP();
            break;
        case 8:
            DELETE_GIVEN();
            DISP();
            break;
        case 9:
            DELETE_END();
            DISP();
            break;
        case 10:
            DELETE_SECOND_LAST();
            DISP();
            break;
        case 11:
            DISP();
            break;
        case 12:
            // getch();
            exit(0);
        default:
            printf("\n INVALID INPUT");
        }
        // getch();
    } while (ch != 12);
}

void CREATE()
{
    struct node *newnode, *temp;
    newnode = malloc(sizeof(struct node));

    printf("\n\n ENTER A NUMBER: ");
    scanf("%d", &newnode->num);

    newnode->next = NULL;

    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void DISP()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("\n\n NO LINKED LIST");
    }
    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf("\n\n %d", temp->num);
            temp = temp->next;
        }
    }
}

void INSERT_BEGIN()
{
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    printf("\n\n ENTER A NUMBER: ");
    scanf("%d", &newnode->num);
    newnode->next = start;
    start = newnode;
}

void INSERT_BEFORE()
{
    int tnum;
    struct node *newnode, *temp;
    printf("\n\n ENTER A TARGET NUMBER : ");
    scanf("%d", &tnum);

    if (tnum == start->num)
    {
        newnode = malloc(sizeof(struct node));
        printf("\n ENTER A NUMBER : ");
        scanf("%d", &newnode->num);
        newnode->next = start;
        start = newnode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL && temp->next->num != tnum)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            printf("\n\n TARGET NUMBER NOT FOUND");
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
    printf("\n\n ENTER A TARGET NUMBER : ");
    scanf("%d", &tnum);

    temp = start;

    while (temp != NULL && temp->num != tnum)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("\n\n TARGET NOT FOUND");
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
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode = malloc(sizeof(struct node));
    printf("\n ENTER A NUMBER : ");
    scanf("%d", &newnode->num);

    newnode->next = NULL;
    temp->next = newnode;
}

void INSERT_NTH_POS()
{
    int n, i = 1;
    struct node *newnode, *temp;

    printf("\n ENTER A NTH NUMBER : ");
    scanf("%d", &n);

    if (n == 0)
    {
        printf("\n INVALID INPUT");
    }
    else if (n == 1)
    {
        INSERT_BEGIN();
    }
    else
    {
        temp = start;
        while (temp != NULL && i == n - 2)
        {
            temp = temp->next;
            i++;
        }
        if (temp == NULL)
        {
            printf("\n INVALID INPUT");
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

void DELETE_BEGIN()
{
    struct node *temp;
    temp = start->next;
    free(start);
    start = temp;
}

void DELETE_GIVEN()
{
    int tnum;
    struct node *temp, *temp2;

    printf("\n ENTER A NUMEBR TO BE DELETED : ");
    scanf("%d", &tnum);

    if (tnum == start->num)
    {
        DELETE_BEGIN();
    }
    else
    {
        temp = start;
        while (temp->next != NULL && temp->next->num != tnum)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            printf("\n NUMBER NOT FOUND ");
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
    if (start->next == NULL)
    {
        free(start);
        start == NULL;
    }
    else
    {
        temp = start;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void DELETE_SECOND_LAST()
{
    struct node *temp = start, *prev = NULL;

    if (start == NULL || start->next == NULL)
    {
        printf("\n NOT ENOUGH NODES TO DELETE SECOND LAST");
        return;
    }

    while (temp->next->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    // Now temp points to the second last node
    if (prev == NULL)
    {
        // This case happens when there are only two nodes
        free(start);
        start = temp->next;
    }
    else
    {
        prev->next = temp->next;
        free(temp);
    }
}
