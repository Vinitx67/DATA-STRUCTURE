#include <stdio.h>
#include <stdlib.h>
#include "DoublyLL.h"

int main()
{
    PersonNode *head = NULL, *tail = NULL;
    int choice, age;
    char name[30];

    while (1)
    {
        printf("\nMENU:\n");
        printf("1. ADD A PERSON\n");
        printf("2. LIST ALL\n");
        printf("3. SEARCH\n");
        printf("4. EDIT\n");
        printf("5. INSERT AFTER\n");
        printf("6. DELETE\n");
        printf("7. SWAP TO PERSON\n");
        printf("8. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            printf("ENTER A NAME: ");
            fgets(name, 30, stdin);
            name[strcspn(name, "\n")] = 0;
            printf("ENTER A AGE: ");
            scanf("%d", &age);
            Append(&head, &tail, name, age);
            ListAll(head);
            break;
        case 2:
            ListAll(head);
            break;
        case 3:
            printf("ENTER A NAME TO SEARCH: ");
            fgets(name, 30, stdin);
            name[strcspn(name, "\n")] = 0;
            PersonNode *foundPerson = Search(head, name);
            if (foundPerson)
            {
                PrintPerson(foundPerson);
            }
            else
            {
                printf("PERSON NOT FOUND!\n");
            }
            break;
        case 4:
            printf("ENTER A NAME TO EDIT: ");
            fgets(name, 30, stdin);
            name[strcspn(name, "\n")] = 0;
            if (!Edit(head, name))
                printf("PERSON NOT FOUND!\n");
            ListAll(head);
            break;
        case 5:
            printf("ENTER EXISTING PERSON NAME: ");
            fgets(name, 30, stdin);
            name[strcspn(name, "\n")] = 0;
            char newname[30];
            int newage;
            printf("ENTER NEW PERSON NAME: ");
            fgets(newname, 30, stdin);
            newname[strcspn(newname, "\n")] = 0;
            printf("ENTER NEW PERSON AGE: ");
            scanf("%d", &newage);
            if (!InsertAfter(head, name, newname, newage))
                printf("PERSON NOT FOUND!\n");
            ListAll(head);
            break;
        case 6:
            printf("ENTER NAME TO DELETE: ");
            fgets(name, 30, stdin);
            name[strcspn(name, "\n")] = 0;
            if (!Delete(&head, &tail, name))
                printf("PERSON NOT FOUND!\n");
            ListAll(head);
            break;
        case 7:
            printf("ENTER FIRST NAME TO SWAP: ");
            fgets(name, 30, stdin);
            name[strcspn(name, "\n")] = 0;
            printf("ENTER SECOND NAME TO SWAP: ");
            fgets(newname, 30, stdin);
            newname[strcspn(newname, "\n")] = 0;
            Swap(Search(head, name), Search(head, newname));
            ListAll(head);
            break;
        case 8:
            printf("EXITING PROGRAM\n");
            return 0;
        default:
            printf("INVALID CHOICE\n");
        }
    }
    return 0;
}
