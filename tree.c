#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int main()
{
    Node *root;
    CreateRoot(&root, "Vinit", 21);
    root->left = CreateNewNode("Sameer", 22);
    root->right = CreateNewNode("Tanishq", 23);
    root->left->left = CreateNewNode("Mandar", 24);
    root->left->right = CreateNewNode("Izhaan", 25);
    printf("\nPre Order:");
    PreOrder(root);
    printf("\nIn Order:");
    InOrder(root);
    printf("\nPost Order:");
    PostOrder(root);
    Node *temp;
    temp = SearchByName("Vinit", root);
    if (temp == NULL)
    {
        printf("\nNOT FOUND");
    }
    else
    {
        printf("\nFOUND");
        PrintData(temp);
    }
    root->left->right->left = CreateNewNode("Ahmad", 26);
    LevelOrder(root);
    free(root);
    root = NULL;
}