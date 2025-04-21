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

    printf("\nPRE ORDER:");
    PreOrder(root);

    printf("\n\nIN ORDER:");
    InOrder(root);

    printf("\n\nPSOT ORDER:");
    PostOrder(root);

    printf("\n\nSEARCHING:");
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

    printf("\n\nPRINTING LEVEL ORDER:");
    root->left->right->left = CreateNewNode("Ahmad", 26);
    LevelOrder(root);

    printf("\n\nAFTER INSERTING:");
    Insert("qausain", 27, &root);
    Insert("aashu", 17, &root);
    Insert("sidhu", 11, &root);
    PreOrder(root);
    ClearTree(root);
    // free(root);
    // root = NULL;
}