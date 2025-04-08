#include <stdio.h>
#include <stdlib.h>

int *arr = NULL;

int InitializeArray(int size)
{
    arr = (int *)malloc(size * sizeof(int));
    // ask the computer to reserve n bytes of memory
    if (arr == NULL)
    {
        printf("UNABLE TO ALLOCATE MEMORY");
        return -1;
    }
    return 0;
}

void GetValues(int size)
{
    int i;
    printf("\n");
    for (i = 0; i < size; i++)
    {
        printf("ENTER VALUE FOR INDEX[%d]:", i);
        scanf("%d", (arr + i));
    }
}

void printArray(int size)
{
    int i;
    printf("\n");
    for (i = 0; i < size; i++)
    {
        printf("%d, ", *(arr + i));
    }
}

void DeleteArray()
{
    free(arr);
    // remove dangling pointer
    arr = NULL;
}

int append(int val, int size)
{
    arr = (int *)realloc(arr, sizeof(int) * (size + 1));
    if (arr == NULL)
    {
        printf("UNABLE TO REALLOCATE MEMORY !!!");
        return -1;
    }
    *(arr + size) = val;
    return 0;
}

int removeAtEnd(int size)
{
    arr = (int *)realloc(arr, sizeof(int) * (size - 1));
    if (arr == NULL)
    {
        printf("UNABLE TO REALLOCATE MEMORY !!!");
        return -1;
    }
    return 0;
}

int IndexOf(int val, int size)
{
    int i;
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) == val)
            return i;
    }
    return -1;
}

int Insert(int pos, int val, int size)
{
    int i;
    if (pos < 0 || pos >= size)
    {
        return -1;
    }
    arr = (int *)realloc(arr, size + 1);
    for (i = size; i > pos; i--)
    {
        *(arr + i) = *(arr + i - 1);
    }
    *(arr + i) = val;
    return 0;
}

int Remove(int pos, int size)
{
    int i;
    if (pos < 0 || pos >= size)
    {
        return -1;
    }
    for (i = pos; i < size; i++)
    {
        *(arr + i) = *(arr + i + 1);
    }
    arr = (int *)realloc(arr, size - 1);
    return 0;
}

int Edit(int val, int newval, int size)
{
    int idx;
    idx = IndexOf(val, size);
    if (idx == -1)
    {
        return -1;
    }
    *(arr + idx) = newval;
    return 0;
}
