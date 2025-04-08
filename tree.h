/*
4 is the root => Topmost Node
    Edge: the connection between nodes (4,8),(8,3) etc
    Parent node: 4,8,5,3,1
    Child nodes: 8,3,6,1,2,5,9,7
    Leaf nodes: 6,2,9,7
    Sibling Nodes: (3,1),(9,7)

    Parent: Any node that has children
    child node: any node that has parent
    leaf: nodes with no children
    sibling: child with same parent

    height: the number of edges from root node to that node

    depth: the number of edges in the longest path from that node to leaf node in the subtree

    height of 1: 2
    depth of 1: 1
    Degree of node: 1 is 1 (no of direct children node has)
    degree od 8 is 2

    Depth first: preOrder: 5,9,7
    Depth First: InOrder: 9,5,7
    Depth First: PostOrder: 9,7,5
    Breadth First: LevelOrder: 5,9,7

        preOrder:
            -5
            /\
           /  \
          -9    -7

        InOrder:
             5
            /|\
           /   \
          9     7
          |     |

        PostOrder:
            5-
            /\
           /  \
        9-     7-

        LevelOrder:
            -5-
             /\
            /  \
         -9-    -7-
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
  char name[20];
  int roll;
  struct Node *left;
  struct Node *right;
};
typedef struct Node Node; // from now on struct node can be written as just node

Node *CreateNewNode(char *name, int roll)
{
  Node *newnode = (Node *)malloc(sizeof(Node));
  if (newnode == NULL)
  {
    return NULL;
  }
  strcpy(newnode->name, name);
  newnode->roll = roll;
  newnode->left = newnode->right = NULL;
  return newnode;
}

void CreateRoot(Node **root, char *name, int roll)
{
  *root = (Node *)CreateNewNode(name, roll);
}

void PrintData(Node *n)
{
  printf("\n%x: %s, (%d), %x, %x", n, n->name, n->roll, n->left, n->right);
}

void PreOrder(Node *n)
{
  if (n == NULL)
  {
    return;
  }
  PrintData(n);
  PreOrder(n->left);
  PreOrder(n->right);
}

void InOrder(Node *n)
{
  if (n == NULL)
  {
    return;
  }
  InOrder(n->left);
  PrintData(n);
  InOrder(n->right);
}

void PostOrder(Node *n)
{
  if (n == NULL)
  {
    return;
  }
  PostOrder(n->left);
  PostOrder(n->right);
  PrintData(n);
}

int Height(Node *n)
{
  if (n == NULL)
  {
    return -1;
  }
  int leftH = Height(n->left);
  int rightH = Height(n->right);
  if (leftH > rightH)
  {
    return leftH + 1;
  }
  else
  {
    return rightH + 1;
  }
}

Node *SearchByName(char *name, Node *root)
{
  Node *t = NULL;
  if (root == NULL)
  {
    return NULL;
  }
  if (strcmp(name, root->name) == 0)
  {
    return root;
  }
  t = SearchByName(name, root->left);
  if (t != NULL)
  {
    return t;
  }
  return SearchByName(name, root->right);
}

void PrintLevel(Node *root, int level)
{
  if (root == NULL)
  {
    return;
  }
  if (level == 1)
  {
    PrintData(root);
  }
  else if (level > 1)
  {
    PrintLevel(root->left, level - 1);
    PrintLevel(root->right, level - 1);
  }
}

void LevelOrder(Node *root)
{
  int h = Height(root);
  for (int i = 1; i <= h + 1; i++)
  {
    printf("\nNOW PRINTING LEVEL %d:", i);
    PrintLevel(root, i);
  }
}
