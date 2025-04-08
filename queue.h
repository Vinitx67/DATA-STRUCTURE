/*
In a queue you can do the following
Enqueue - Add an item at the end of the queue
Dequeue - remove an item from the beginning of the queue
Peek - see the item that can be dequeued
List
Search
Edit

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("\nName: %s, Age: %d, Next -> %p", t->name, t->age, (void *)t->next);
}

void Enqueue(PersonNode **head, PersonNode **tail, char *name, int age)
{
    PersonNode *newnode = CreateNewPerson(name, age);
    if (newnode == NULL)
        return;

    if (*tail == NULL)
    {
        *head = *tail = newnode;
    }
    else
    {
        (*tail)->next = newnode;
        *tail = newnode;
    }
}

int Dequeue(PersonNode **head, PersonNode **tail)
{
    if (*head == NULL)
    {
        return 0;
    }
    PersonNode *t = *head;
    *head = (*head)->next;
    if (*head == NULL)
        *tail = NULL;
    free(t);
    return 1;
}

PersonNode *Peek(PersonNode **head)
{
    return *head;
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

int Edit(PersonNode *head, char *name)
{
    PersonNode *toEdit = Search(head, name);
    if (toEdit == NULL)
    {
        printf("\nPerson not found.");
        return 0; // false
    }
    printf("\nOld Data: ");
    PrintPerson(toEdit);
    printf("\nEnter new name: ");
    scanf(" %19[^\n]", toEdit->name);
    printf("\nEnter new age: ");
    scanf("%d", &toEdit->age);
    fflush(stdin);
    printf("\nPerson details updated.");
    ListAll(head);
    return 1;
}