#include <stdio.h>
#include <conio.h>
// #include <alloc.h>
#include <string.h>

void main()
{
    char *str;

    clrscr();

    str = malloc(10);

    strcpy(str, "computer");

    printf("\n\n str = %s", str);

    free(str);

    getch();
}