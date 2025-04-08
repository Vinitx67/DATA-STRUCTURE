#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int main()
{
    PersonNode *head = NULL, *tail = NULL;
    int choice, age;
    char name[20];

    do
    {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. List All\n");
        printf("5. Search\n");
        printf("6. Edit\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
        case 1:
            printf("Enter name: ");
            scanf("%19[^\n]", name);
            printf("Enter age: ");
            scanf("%d", &age);
            Enqueue(&head, &tail, name, age);
            break;
        case 2:
            Dequeue(&head, &tail);
            ListAll(head);
            break;
        case 3:
            if (Peek(&head))
                PrintPerson(Peek(&head));
            else
                printf("\nQueue is empty.");
            break;
        case 4:
            ListAll(head);
            break;
        case 5:
            printf("Enter name to search: ");
            scanf("%19[^\n]", name);
            if (Search(head, name))
                PrintPerson(Search(head, name));
            else
                printf("\nPerson not found.");
            break;
        case 6:
            printf("Enter name to edit: ");
            scanf("%19[^\n]", name);
            Edit(head, name);
            break;
        case 7:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
