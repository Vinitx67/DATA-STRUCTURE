#include <stdio.h>

void merge(int[], int, int, int);
void mergeSort(int[], int, int);

void main()
{
    int size, x[30], i;

    printf("ENTER A SIZE : ");
    scanf("%d", &size);

    printf("ENTER A NUMBER : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
    }

    mergeSort(x, 0, size - 1);
}

void mergeSort(int x[], int beg, int end)
{
    int mid;

    if (beg < end)
    {
        mid = (beg + end) / 2;
        mergeSort(x, beg, mid);
        mergeSort(x, mid + 1, end);
        merge(x, beg, mid, end);
    }
}

void merge(int x[], int beg, int mid, int end)
{
    int i = beg, j = mid + 1, k = beg, temp[100];

    while (i <= mid && j <= end)
    {
        if (x[i] < x[j])
        {
            temp[k] = x[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = x[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = x[i];
        k++;
        i++;
    }
    while (j <= end)
    {
        temp[k++] = x[j++];
    }

    printf("\nMERGE SORT : \n");
    for (i = beg; i < k; i++)
    {
        x[i] = temp[i];
        printf("%d ", x[i]);
    }
}
