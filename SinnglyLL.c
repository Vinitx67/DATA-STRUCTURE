#include <stdio.h>
#include "SinnglyLL.h"
int main()
{
    PersonNode *head = NULL;
    PersonNode *tail = NULL;

    // Append(&head, &tail, "Vinit", 20);
    // Append(&head, &tail, "Sameer", 21);
    // Append(&head, &tail, "Tanishq", 22);
    // Append(&head, &tail, "Mandar", 23);
    // ListAll(head);
    // Edit(head, "Mandar");
    // ListAll(head);
    // InsertAfter(head, "Tanishq", "Ahmad", 35);
    // ListAll(head);

    // printf("\nBefore Swapping:\n");
    // ListAll(head);
    // Swap(Search(head, "Sameer"), Search(head, "Tanishq"));
    // printf("\nAfter Swapping:\n");
    // ListAll(head);

    displayMenu(&head, &tail);
}

// CREATE MENU