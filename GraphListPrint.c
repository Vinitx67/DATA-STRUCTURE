#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GraphList.h"

// int main()
// {
//     Graph *g = CreateGraph();
//     Student s = {"Alice", 1};
//     Add(g, s);
//     Student s2 = {"Bob", 2};
//     Add(g, s2);
//     Student s3 = {"Charlie", 3};
//     Add(g, s3);
//     AddFriend(g, 1, 2);
//     AddFriend(g, 1, 3);
//     Print(g);
//     printf("\nDELETING STUDENT DETAILS:\n");
//     DeleteStudent(g, 1);
//     Print(g);
//     // printf("\nUPDATING STUDENT DETAILS:\n");
//     // UpdateStudent(g, 2, "Vinit");
//     // Print(g);
// }

int main()
{
    Graph *g = CreateGraph();

    // Create and add students
    Student students[] = {
        {"Alice", 1},
        {"Bob", 2},
        {"Charlie", 3},
        {"David", 4},
        {"Eve", 5},
        {"Frank", 6},
        {"Grace", 7},
        {"Heidi", 8},
        {"Ivan", 9},
        {"Judy", 10}};

    for (int i = 0; i < 10; i++)
    {
        Add(g, students[i]);
    }

    // Add complex friend connections
    AddFriend(g, 1, 2);
    AddFriend(g, 1, 3);
    AddFriend(g, 2, 4);
    AddFriend(g, 2, 5);
    AddFriend(g, 3, 6);
    AddFriend(g, 3, 7);
    AddFriend(g, 4, 5);
    AddFriend(g, 5, 6);
    AddFriend(g, 6, 7);
    AddFriend(g, 7, 8);
    AddFriend(g, 8, 9);
    AddFriend(g, 9, 10);
    AddFriend(g, 10, 1); // Creating a cycle

    // Print graph
    printf("Initial Graph:\n");
    Print(g);

    // Delete a student with many connections
    printf("\nDeleting student with roll 3 (Charlie):\n");
    DeleteStudent(g, 3);
    Print(g);

    // Update a student name
    printf("\nUpdating student 5 (Eve) to name \"Eva\":\n");
    UpdateStudent(g, 5, "Eva");
    Print(g);

    // Delete a leaf node (only 1 or 0 friends)
    printf("\nDeleting student with roll 10 (Judy):\n");
    DeleteStudent(g, 10);
    Print(g);

    return 0;
}
