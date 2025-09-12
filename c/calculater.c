#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int dollars = 1;
    char n = get_char("%i$here,double the price or not: ", dollars);
    do
    {
        dollars *= 2;
        n = get_char("%i$here,double the price or not: ", dollars);
    } while (n == 'y' || n == 'Y');
    printf("The price is now %i$\n", dollars);
    return 0;
}