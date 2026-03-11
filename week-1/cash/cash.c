#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents;

    // Prompt the user for change owed, in cents
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    int coins = 0;

    int quarters = calculate_quarters(cents);
    coins += quarters;
    cents -= quarters * 25;

    int dimes = calculate_dimes(cents);
    coins += dimes;
    cents -= dimes * 10;

    int nickels = calculate_nickels(cents);
    coins += nickels;
    cents -= nickels * 5;

    int pennies = calculate_pennies(cents);
    coins += pennies;
    cents -= pennies * 1;

    printf("%i\n", coins);
}

int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents -= 25;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents -= 10;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5)
    {
        nickels++;
        cents -= 5;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    int pennies = 0;
    while (cents >= 1)
    {
        pennies++;
        cents -= 1;
    }
    return pennies;
}