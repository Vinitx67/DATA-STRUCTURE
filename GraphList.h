#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[20];
    int roll;
};
typedef struct Student Student;

// TO STORE FRIENDS CONNECTIONS
struct Node
{
    Student data;
    struct Node *next;
};
typedef struct Node Node;

// TO STORE THE STUDENTS IN THE GRAPH
// A GRAPH NODE CAN CONNECT TO MANY OTHER NODES -> HENCE AJLIST
struct GraphNode
{
    Student data;
    Node *adjlist;          // CONNECTIONS
    struct GraphNode *next; // NEXT ELEMENT (IN A LIST - WHY ? TO KNOW HOW MANY NODE ARE THERE IN THE GRAPH)
};
typedef struct GraphNode GraphNode;

// THE ROOT OF THE GRAPH BASICALLY WE START FROM HERE (JUST LIKE ROOT OF A TREE)
// UNLINE A TREE A GRAPH HAS NO ROOT AND WE CAN START FROM ANYWHERE THIS IS JUS FOR CODE CONVINIENCE
struct Graph
{
    GraphNode *head;
    int vertices;
};
typedef struct Graph Graph;

// CREATE A NEW GRAPH
Graph *CreateGraph()
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    if (g == NULL)
    {
        return NULL;
    }
    g->head = NULL;
    g->vertices = 0;
    return g;
}

GraphNode *CreateGraphNode(Student s)
{
    GraphNode *n = (GraphNode *)malloc(sizeof(GraphNode));
    if (n == NULL)
    {
        return NULL;
    }
    n->data = s;
    n->adjlist = NULL;
    n->next = NULL;
    return n;
}

GraphNode *find(Graph *g, int roll)
{
    GraphNode *t = g->head;
    while (t)
    {
        if (t->data.roll == roll)
        {
            // printf("\nALREADY EXIST");
            return t;
        }
        t = t->next;
    }
    return NULL;
}

void Add(Graph *g, Student s)
{
    GraphNode *t = find(g, s.roll);
    GraphNode *temp;
    // IF NODE/VERTICE ALREADY EXISTS, NO NEED TO ADD
    if (t != NULL)
    {
        // printf("\nALREADY EXIST");
        return;
    }
    // CREATE A NEW GRAPH NODE TO BE ADDED
    t = CreateGraphNode(s);
    if (t == NULL)
    {
        return;
    }
    // IF THE GRAPH IS EMPTY -> ADD IT TO THE HEAD
    if (g->head == NULL)
    {
        g->head = t;
    }
    // IF GRAPH IS NOT EMPTY -> ADD IT AT THE END
    else
    {
        temp = g->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = t;
    }
    g->vertices++;
}

void Add2(Graph *g, Student s)
{
    GraphNode *t = find(g, s.roll);
    GraphNode *temp;
    // IF NODE/VERTICE ALREADY EXISTS, NO NEED TO ADD
    if (t != NULL)
    {
        // printf("\nALREADY EXIST");
        return;
    }
    // CREATE A NEW GRAPH NODE TO BE ADDED
    t = CreateGraphNode(s);
    if (t == NULL)
    {
        return;
    }
    // IF THE GRAPH IS EMPTY -> ADD IT TO THE HEAD
    if (g->head == NULL)
    {
        g->head = t;
    }
    // IF GRAPH IS NOT EMPTY -> ADD IT AT THE END
    else
    {
        temp = g->head->next; // 1ST ELEMENT IN THE LIST
        g->head = t;          // NEW HEAD IS THE NEW ELEMENT
        t->next = temp;       // ITS NEXT IS THE OLD ELEMENT
    }
    g->vertices++;
}

void AddtoAdjList(Node **head, Student s)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = s;
    n->next = *head;
    *head = n;
}

void AddFriend(Graph *g, int roll1, int roll2)
{
    GraphNode *s1 = find(g, roll1);
    GraphNode *s2 = find(g, roll2);
    if (s1 == NULL || s2 == NULL)
    {
        printf("\nONE OR MORE STUDENTS NOT FOUND");
        return;
    }
    AddtoAdjList(&s1->adjlist, s2->data);
    AddtoAdjList(&s2->adjlist, s1->data);
}

void PrintStudent(Student s)
{
    printf("%s (%d) -->", s.name, s.roll);
}

void Print(Graph *g)
{
    GraphNode *temp = g->head;
    Node *adj;
    while (temp != NULL)
    {
        printf("\n");
        PrintStudent(temp->data);
        adj = temp->adjlist;
        while (adj != NULL)
        {
            PrintStudent(adj->data);
            adj = adj->next;
        }
        printf("NULL\n");
        temp = temp->next;
    }
}

void UpdateStudent(Graph *g, int roll, char *newName)
{
    GraphNode *studentNode = find(g, roll);
    if (studentNode == NULL)
    {
        printf("\nSTUDENT WITH ROLL NUMDER %d NOT FOUND\n", roll);
        return;
    }

    strncpy(studentNode->data.name, newName, sizeof(studentNode->data.name) - 1);
    studentNode->data.name[sizeof(studentNode->data.name) - 1] = '\0'; // ensure null termination
    printf("\nSTUDENT UPDATED SUCCESSFULLY\n");
}

void RemoveFromAdjacencyList(Node **head, int roll)
{
    Node *t = *head;
    Node *prev = NULL;
    while (t)
    {
        if (t->data.roll == roll)
        {
            if (prev)
            {
                prev->next = t->next;
            }
            else
            {
                *head = t->next;
            }
            free(t);
            return;
        }
        prev = t;
        t = t->next;
    }
}

void DeleteStudent(Graph *g, int roll)
{
    // IF THE GRAPH IS EMPTY OR DOES NOT EXITS => EXIT
    if (g == NULL || g->head == NULL)
    {
        return;
    }
    GraphNode *temp;
    GraphNode *t = g->head;
    GraphNode *prev = NULL;
    Node *n, *toDelete;
    // FIND THE STUDENT TO DELETE
    while (t)
    {
        if (t->data.roll == roll)
        {
            break;
        }
        prev = t;
        t = t->next;
    }
    // IF STUDENT IS NOT FOUND T WILL BE NULL AS WE WILL REACH THE END OF THE LIST
    if (t == NULL)
    {
        printf("\nSTUDENT NOT FOUNND");
        return;
    }
    // CHECK THE ADJACENCY LIST OF T
    n = t->adjlist;
    while (n)
    {
        temp = g->head;
        // FIND THE FRIEND IN THE GRAPH
        while (temp)
        {
            if (temp->data.roll == n->data.roll)
            {
                break;
            }
            temp = temp->next;
        }
        // IF FRIEND IS FOUND REMOVE THE STUDENT TO BE DELETEDEFROM ITS ADJACENCY LIST
        if (temp)
        {
            RemoveFromAdjacencyList(&temp->adjlist, t->data.roll);
        }
        // DELETE THE FRIEND FROM THE STUDENTS ADJACENCY LIST
        toDelete = n;
        n = n->next;
        free(toDelete);
    }
    // REMOVE THE STUDENT FROM THE MAIN GRAPH (REMOVE THE VERTICE)
    if (prev)
    {
        // IF STUDENT IS NOT THE HEAD OF THE GRAPH
        prev->next = t->next;
    }
    else
    {
        // IF STUDENT IS THE HEAD OD THE GRAPH
        g->head = t->next;
    }
    free(t);
    // THERE IS NOW 1 LESS VERTICE
    g->vertices--;
}
