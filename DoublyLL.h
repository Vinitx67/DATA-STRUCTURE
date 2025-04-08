#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct PersonNode
{
    char name[30];
    int age;
    struct PersonNode *next, *prev;
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
    newnode->next = newnode->prev = NULL;
    return newnode;
}

void PrintPerson(PersonNode *t)
{
    printf("\nPREV->%x, NAME: %s, AGE: %d, NEXT -> %x", t->prev, t->name, t->age, t->next);
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
        newnode->prev = *tail;
        *tail = newnode;
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
    newNode->prev = prevNode;
    newNode->next = nextNode;
    nextNode->prev = newNode;
    return 1;
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
        t->next = NULL;
        (*head)->prev = NULL;
        // if there is just one element int the list set the tail to the null
        if (*head == NULL)
        {
            *tail = NULL;
        }
    }
    else
    {
        prev->next = t->next;
        if (t->next == NULL)
        {
            *tail = prev;
        }
        else
        {
            t->next->prev = prev;
        }
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

void Swap(PersonNode *a, PersonNode *b)
{
    if (a == NULL || b == NULL)
    {
        printf("Swap not possible!\n");
        return;
    }

    // SWAP NAME
    char tempName[30];
    strcpy(tempName, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name, tempName);

    // SWAP AGE
    int tempAge = a->age;
    a->age = b->age;
    b->age = tempAge;
}
