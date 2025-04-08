#include <stdio.h>
#include <stdlib.h>
#include "ArrDynamic.h"

int main()
{
    int size;
    printf("HOW MANY MARKS DO YOU WANT TO GET FROM THE USER : ");
    scanf("%d", &size);
    if (InitializeArray(size) == -1)
    {
        return -1;
    }
    GetValues(size);
    printArray(size);

    printf("\nAPPENDING 66");
    append(66, size);
    size++;
    printArray(size);

    printf("\nDROPPING 66");
    removeAtEnd(size);
    size--;
    printArray(size);

    // printf("%d", IndexOf(33, size));

    printf("\nINSERTING 45 AT INDEX 3");
    Insert(3, 45, size);
    size++;
    printArray(size);

    printf("\nREMOVING 45 AT INDEX 3");
    Remove(3, size);
    size--;
    printArray(size);

    printf("\nEDITING");
    Edit(50, 100, size);
    printArray(size);

    printf("\nDELETING ARRAY");
    DeleteArray();
}