#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    float change;
    int count = 0;
    int cents;

    // asking user for amount change due
    do
    {
        printf("O hai! How much change is owed? \n");
        change = get_float();
    }
    while (change < 0.0);
    // will continue to ask for amount due if change is less than zero

    // need to convert the change input into cents and round it

    cents = round(change * 100);

    // to determine if quarters can be used

    while (cents >= 25)
    {
       count++;
       cents = cents - 25;
    }

    // to determine if dimes can be used

    while (cents >= 10)
    {
       count++;
       cents = cents - 10;
    }

    // to determine if nickles can be used

    while (cents >= 5)
    {
        count++;
        cents = cents - 5;
    }

    // to determine if pennies can be used

    while (cents > 0)
    {
        count++;
        cents = cents - 1;
    }

    // prints the amount of change that was used
    printf("%d\n", count);
}