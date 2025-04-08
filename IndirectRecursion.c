#include <stdio.h>
// prototyping a function ->
void turnOff(int);

void turnOn(int count)
{
    if (count == 0)
    {
        return;
    }
    printf("\nLED IS ON");
    turnOff(count - 1);
}

void turnOff(int count)
{
    if (count == 0)
    {
        return;
    }
    printf("\nLED IS OFF");
    turnOn(count - 1);
}

int main()
{
    turnOn(10);
}