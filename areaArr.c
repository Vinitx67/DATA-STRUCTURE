// Write a C program that takes an array of heights representing vertical lines on a 2D plane.The program should determine the maximum area of water that can be contained between any two lines.The width between two lines is given by their indices, and the height is determined by the shorter line.Print the maximum area.

#include <stdio.h>
void main()
{
    int heights[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int i, j, size = 9, width, height, area, max = 0;

    for (i = 0, j = size - 1; i < j;)
    {
        width = j - i;
        height = (heights[i] <= heights[j]) ? heights[i] : heights[j];
        area = width * height;
        if (max <= area)
        {
            max = area;
        }
        if (heights[i] <= heights[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    printf("MAXAREA : %d ", max);
}