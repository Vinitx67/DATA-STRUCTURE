#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <alloc.h>

void main()
{
    char *str;

    str = calloc(10, 1);
    strcpy(str, "HELLO");
    printf("STR : %s\n", str);

    free(str);
}