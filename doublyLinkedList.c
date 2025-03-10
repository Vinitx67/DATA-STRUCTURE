#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *prev;
    struct node *next;
} *start = NULL;

void CREATE();
void INSERT_BEGIN();
void INSERT_BEFORE();
void INSERT_AFTER();
void INSERT_END();
void DELETE_BEGIN();
void DELETE_GIVEN();
void PRINT_MIDDLE();
void DISP();

int menu()
{
    int choice;
    // clrscr();
    printf("\n\n 1] CREATE A DOUBLY LINKED LIST");
    printf("\n 2] INSERT AT BEGINING");
    printf("\n 3] INSERT AT BEFORE");
    printf("\n 4] INSERT AT AFTER");
    printf("\n 5] INSERT AT END");
    printf("\n 6] DELETE BEGIN");
    printf("\n 7] DELETE AT GIVEN");
    printf("\n 8] PRINT AT MIDDLE");
    printf("\n 9] DISPLAY A DOUBLY LINKED LIST");
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
            PRINT_MIDDLE();
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

    newnode->next = NULL;

    if (start == NULL)
    {
        start = newnode;
        start->prev = NULL;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void DISP()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("\n NO DOUBLY LINKED LIST");
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

    printf("\n ENTER A NUMBER : ");
    scanf("%d", &newnode->num);

    newnode->prev = NULL;
    newnode->next = start;
    start->prev = newnode;
    start = newnode;
}

void INSERT_BEFORE()
{
    int tnum;
    struct node *newnode, *temp;

    printf("\n ENTER A TARGET NUMBER : ");
    scanf("%d", &tnum);

    if (tnum == start->num)
    {
        INSERT_BEGIN();
    }
    else
    {
        temp = start->next;
        while (temp != NULL && temp->num != tnum)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("\n\nTARGET NOT FOUND");
        }
        else
        {
            newnode = malloc(sizeof(struct node));
            printf("\n ENTER A NUMBER : ");
            scanf("%d", &newnode->num);

            newnode->prev = temp->prev;
            newnode->next = temp;
            temp->prev->next = newnode;
            temp->prev = newnode;
        }
    }
}

void INSERT_AFTER()
{
    int tnum;
    struct node *newnode, *temp;

    printf("\n ENTER A TARGET NUMBER: ");
    scanf("%d", &tnum);

    temp = start;

    while (temp != NULL && temp->num != tnum)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("NUMBER NOT FOUND");
    }
    else
    {
        newnode = malloc(sizeof(struct node));
        printf("ENTER A NUMBER:");
        scanf("%d", &newnode->num);

        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
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
    printf("ENTER A NUMBER:");
    scanf("%d", &newnode->num);

    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = NULL;
}

void DELETE_BEGIN()
{
    struct node *temp;
    temp = start->next;
    free(start);
    start = temp;
    start->prev = NULL;
}

void DELETE_GIVEN()
{
    int tnum;
    struct node *temp;

    printf("\n ENTER A TARGET NUMBER: ");
    scanf("%d", &tnum);

    if (tnum == start->num)
    {
        DELETE_BEGIN();
    }
    else
    {
        temp = start->next;
        while (temp != NULL && temp->num != tnum)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("NUMBER NOT FOUND");
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
    }
}

void PRINT_MIDDLE()
{
    struct node *slow = start, *fast = start;

    if (start == NULL)
    {
        printf("\nThe list is empty.");
        return;
    }

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("\nMiddle element is: %d", slow->num);
}
