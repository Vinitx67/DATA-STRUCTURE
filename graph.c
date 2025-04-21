/*
    A
   / \
  B---C
       \
        D

    ADJACECNCY MATRIX: A TRE IS A GRAPH
    IN A UNDIRECTED GRAPH -> THE ADJACENCY MATRIX IS SYMMETRIC

      A B C D
    A 0 1 1 0
    B 1 0 1 0
    C 1 1 0 1
    D 0 0 1 0

      A B C D E
    A 0 1 0 1 0
    B 1 0 1 0 1
    C 0 1 0 0 1
    D 1 0 0 0 1
    E 0 1 1 1 0


    A -> B -> C
    |
    D -> E

    A B C D E
    A 0 1 0 1 0
    B 0 0 1 0 0
    C 0 0 0 0 0
    D 0 0 0 0 1
    E 0 0 0 0 0

    // WEIGHTED GRAPH SHOWING DISTANCE BETWEEN CITIES
    A----B
    |    |\
    |    | \
    |    |  C
    |    | /
    |    |/
    D----E

    A. NAVI MUMBAI
    B. VAPI
    C. NASHIK
    D. PUNE
    E. SOLAPUR


       A      B       C       D       E
  A    0      180     0       120     0
  B    180    0       150     0       500
  C    0      150     0       0       400
  D    120    0       0       0       450
  E    0      500     400     450     0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 5
// const -> cannot change
int graph[MAX_NODES][MAX_NODES];

struct Student
{
    char name[20];
    int roll;
};
typedef struct Student Student;

Student stdfour[MAX_NODES] = {
    {"Vinit", 32},   // 0
    {"Sameer", 45},  // 1
    {"Tanishq", 23}, // 2
    {"Mandar", 48},  // 3
    {"Izhaan", 12}}; // 4

/*
    32----45
     |    /\
     |   /  \
     |  /    -----\
      23----12----48
    // ADD EDGE
*/

int IndexOf(int roll)
{
    int i;
    for (i = 0; i < MAX_NODES; i++)
    {
        if (stdfour[i].roll == roll)
        {
            return i;
        }
    }
    return -1;
}

void AddFriend(int roll1, int roll2)
{
    int i1, i2;
    i1 = IndexOf(roll1);
    i2 = IndexOf(roll2);
    if (i1 == -1 || i2 == -1)
    {
        return;
    }
    graph[i1][i2] = 1;
    graph[i2][i1] = 1;
    // UNDIRECTED GRAPH
}
// SET ALL ELEMENTS IN THE GRAPH TO 0
void ResetGraph()
{
    int i, j;
    for (i = 0; i < MAX_NODES; i++)
    {
        for (j = 0; j < MAX_NODES; j++)
        {
            graph[i][j] = 0;
        }
    }
}

// DeleteFriend(23,45)
// PrintFriendsFor(45)

void DeleteFriend(int roll1, int roll2)
{
    int i1 = IndexOf(roll1);
    int i2 = IndexOf(roll2);

    if (i1 == -1 || i2 == -1)
    {
        printf("NOT FOUND\n");
        return;
    }

    graph[i1][i2] = 0;
    graph[i2][i1] = 0;
}

void PrintFriendsFor(int roll)
{
    int idx = IndexOf(roll);
    if (idx == -1)
    {
        printf("STUDENT WITH ROLL %d NOT FOUND\n", roll);
        return;
    }

    printf("FRIENDS OF %s (Roll: %d):\n", stdfour[idx].name, roll);
    int found = 0;
    for (int j = 0; j < MAX_NODES; j++)
    {
        if (graph[idx][j] == 1)
        {
            printf(" - %s (Roll: %d)\n", stdfour[j].name, stdfour[j].roll);
            found = 1;
        }
    }

    if (!found)
    {
        printf("NO FRIENDS FOUND\n");
    }
}

void PrintAllFriends()
{
    for (int i = 0; i < MAX_NODES; i++)
    {
        PrintFriendsFor(stdfour[i].roll);
        printf("\n");
    }
}

int main()
{
    ResetGraph();
    AddFriend(32, 23);
    AddFriend(32, 45);
    AddFriend(23, 45);
    AddFriend(23, 12);
    AddFriend(12, 48);
    AddFriend(45, 48);

    DeleteFriend(23, 45);

    PrintAllFriends();
}