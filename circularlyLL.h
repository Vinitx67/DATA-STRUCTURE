// for unchanging data dynamic array is used
// for data which changes all the time for that we use list
// 1000 list me 500th data read krna h to start to 500 read krna pdega list me
// array me index number use krke direct read kr skte -> arr + 500
// random read faster hai array me in compare to list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct PersonNode
{
    char name[30];
    int age;
    struct PersonNode *next;
};

typedef struct PersonNode PersonNode;

PersonNode *CreateNewPerson(char *name, int age)
{
    PersonNode *newnode = (PersonNode *)malloc(sizeof(PersonNode));
    if (newnode == NULL)
    {
        printf("UNABLE TO ADD");
        return NULL;
    }
    strcpy(newnode->name, name);
    newnode->age = age;
    newnode->next = NULL;
    return newnode;
}

void PrintPerson(PersonNode *t)
{
    printf("\nNAME: %s, AGE: %d, NEXT -> %x", t->name, t->age, t->next);
}

void Append(PersonNode **head, PersonNode **tail, char *name, int age)
{
    PersonNode *newnode = CreateNewPerson(name, age);
    if (newnode == NULL)
    {
        return;
    }
    if (*head == NULL)
    {
        *head = *tail = newnode;
    }
    else
    {
        (*tail)->next = newnode;
        *tail = newnode;
        // reconnect tail to the head (circular)
        (*tail)->next = *head;
    }
}

PersonNode *Search(PersonNode *head, char *name)
{
    PersonNode *t = head;
    do
    {
        if (strcmp(t->name, name) == 0)
        {
            return t;
        }
        t = t->next;
    } while (t != head);
    return NULL;
}

void ListAll(PersonNode *head)
{
    PersonNode *t = head;
    do
    {
        PrintPerson(t);
        t = t->next;
    } while (t != head);
}

int Edit(PersonNode *head, char *name)
{
    PersonNode *toEdit = Search(head, name);

    if (toEdit == NULL)
    {
        return 0;
    }
    printf("\nOLD DATA :");
    PrintPerson(toEdit);

    printf("\nENTER NEW NAME : ");
    scanf("%19[^\n]", toEdit->name);

    printf("\nENTER NEW AGE : ");
    scanf("%d", &toEdit->age);
    fflush(stdin);

    return 1;
}

int InsertAfter(PersonNode *head, char *name, char *newname, int newage)
{
    PersonNode *prevNode = Search(head, name);
    PersonNode *nextNode = NULL, *newNode = NULL;
    if (prevNode == NULL)
    {
        return 0;
    }
    nextNode = prevNode->next;
    newNode = CreateNewPerson(newname, newage);

    if (newNode == NULL)
    {
        return 0;
    }

    prevNode->next = newNode;
    newNode->next = nextNode;
    return 1;
}

void Swap(PersonNode *a, PersonNode *b)
{
    if (a == NULL || b == NULL)
    {
        printf("Swap not possible!\n");
        return;
    }

    // Swap name
    char tempName[30];
    strcpy(tempName, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name, tempName);

    // Swap age
    int tempAge = a->age;
    a->age = b->age;
    b->age = tempAge;
}

int Delete(PersonNode **head, PersonNode **tail, char *name)
{
    PersonNode *t = *head, *prev = NULL;

    // if the list is empty do nothing
    if (*head == NULL)
    {
        return 0;
    }
    // search for the name while keeping track of the previous element in prev
    while (t != NULL)
    {
        if (strcmp(t->name, name) == 0)
        {
            // if found, exit the loop
            break;
        }
        prev = t;
        t = t->next;
    }
    // if not found exit
    if (t == NULL)
    {
        return 0;
    }
    // you are deleting the first node
    if (prev == NULL)
    {
        *head = t->next;
        // if there is just one element int the list set the tail to the null
        if (*head == NULL)
        {
            *tail = NULL;
        }
    }
    else
    {
        prev->next = t->next;
        // if u are deleting the last element set the tail to prev
        if (t->next == NULL)
        {
            *tail = prev;
        }
    }
    // free the memory
    free(t);
    t = NULL;
    return 1;
}

void displayMenu(PersonNode **head, PersonNode **tail)
{
    int choice;
    char name[30], newname[30];
    int age;

    do
    {
        printf("\n MENU ");
        printf("\n1. Add Person");
        printf("\n2. Search Person");
        printf("\n3. Edit Person");
        printf("\n4. Delete Person");
        printf("\n5. Insert After");
        printf("\n6. List All");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // To handle newline issue after scanf

        switch (choice)
        {
        case 1:
            printf("Enter Name: ");
            scanf("%29[^\n]", name);
            getchar();
            printf("Enter Age: ");
            scanf("%d", &age);
            getchar();
            Append(head, tail, name, age);
            break;

        case 2:
            printf("Enter Name to Search: ");
            scanf("%29[^\n]", name);
            getchar();
            PersonNode *found = Search(*head, name);
            if (found)
            {
                printf("\nPerson Found: ");
                PrintPerson(found);
            }
            else
            {
                printf("\nPerson Not Found!");
            }
            break;

        case 3:
            printf("Enter Name to Edit: ");
            scanf("%29[^\n]", name);
            getchar();
            if (Edit(*head, name))
            {
                printf("\nPerson Updated Successfully!");
            }
            else
            {
                printf("\nPerson Not Found!");
            }
            break;

        case 4:
            printf("Enter Name to Delete: ");
            scanf("%29[^\n]", name);
            getchar();
            if (Delete(head, tail, name))
            {
                printf("\nPerson Deleted Successfully!");
            }
            else
            {
                printf("\nPerson Not Found!");
            }
            break;

        case 5:
            printf("Enter Name to Insert After: ");
            scanf("%29[^\n]", name);
            getchar();
            printf("Enter New Person's Name: ");
            scanf("%29[^\n]", newname);
            getchar();
            printf("Enter New Person's Age: ");
            scanf("%d", &age);
            getchar();
            if (InsertAfter(*head, name, newname, age))
            {
                printf("\nPerson Inserted Successfully!");
            }
            else
            {
                printf("\nPerson Not Found!");
            }
            break;

        case 6:
            printf("\nList of All Persons:\n");
            ListAll(*head);
            break;

        case 7:
            printf("\nExiting program...\n");
            break;

        default:
            printf("\nInvalid choice! Please try again.");
        }
    } while (choice != 7);
}