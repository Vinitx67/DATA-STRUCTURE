// Stack -->
/*
Push (ad at the top)
Pop (remove the book at the top) (Delete from Top)
Peek -> See which book is at the top
We cannot
Insert, Delete from middle, Add at the end
STack of Books
insertAtTheBeginning (Push)
No tail, just head  -> Singly linked List -> Traverse in just one direction
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 1 means Ok, 0 means error
struct PersonNode
{
    char name[20];
    int age;
    struct PersonNode *next;
};
typedef struct PersonNode PersonNode;
PersonNode *CreateNewPerson(char *name, int age)
{
    PersonNode *newnode = (PersonNode *)malloc(sizeof(PersonNode));
    if (newnode == NULL)
    {
        printf("\nUnable to add");
        return NULL;
    }
    strcpy(newnode->name, name);
    newnode->age = age;
    newnode->next = NULL;
    return newnode;
}

void PrintPerson(PersonNode *t)
{
    printf("\nName: %s, Age: %d, Next -> %x", t->name, t->age, t->next);
}

void Push(PersonNode **head, char *name, int age)
{
    PersonNode *newnode = CreateNewPerson(name, age);
    if (newnode == NULL)
        return;

    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        newnode->next = *head;
        *head = newnode;
    }
}
PersonNode *Search(PersonNode *head, char *name)
{
    PersonNode *t = head;
    while (t != NULL)
    {
        if (strcmp(t->name, name) == 0)
        {
            return t;
        }
        t = t->next;
    }
    return NULL;
}
void ListAll(PersonNode *head)
{
    PersonNode *t = head;
    while (t != NULL)
    {
        PrintPerson(t);
        t = t->next;
    }
}
int Edit(PersonNode *head, char *name)
{
    PersonNode *toEdit = Search(head, name);

    if (toEdit == NULL)
        return 0; // false
    printf("\nOld Data: ");
    PrintPerson(toEdit);
    printf("\nEnter new name: ");
    scanf(" %19[^\n]", toEdit->name);
    printf("\nEnter new age: ");
    scanf("%d", &toEdit->age);
    fflush(stdin);
    ListAll(head);
    return 1;
}

int Pop(PersonNode **head)
{
    PersonNode *t = *head;

    // if the list is empty - do nothing
    if (*head == NULL)
    {
        return 0;
    }
    *head = (*head)->next;
    free(t);
    t = NULL;
    return 1;
}
PersonNode *Peek(PersonNode **head)
{
    return *head;
}