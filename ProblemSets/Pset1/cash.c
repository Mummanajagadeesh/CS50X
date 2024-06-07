#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Calculate how many quarters you should give customer
    int quarters = calculate_quarters(cents);

    printf("%i\n", quarters);
}

int calculate_quarters(int cents)
{
    // Calculate how many quarters you should give customer
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    while (cents >= 10)
    {
        quarters++;
        cents = cents - 10;
    }
    while (cents >= 5)
    {
        quarters++;
        cents = cents - 5;
    }
    while (cents >= 1)
    {
        quarters++;
        cents = cents - 1;
    }
    return quarters;
}
