#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int minutes;
    int bottlesPerMinute = 12;
    int bottles;

    printf("minutes: ");

    do
    {
        minutes = get_int();
    }  while (minutes < 0);

    bottles = bottlesPerMinute * minutes;
    printf("number of bottles: %i\n", bottles);
}




