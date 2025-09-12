#include <stdio.h>

#include <cs50.h>

int main(void)
{
    // Prompt user for a positive integer
    int n;
    do
    {
        n = get_int("Height: ");
    } while (n < 1);

    // Print the pyramid
    for (int i = 0; i < n; i++)
    {
        // Print leading spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        // Print hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("  "); // Two spaces between the two pyramids
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        // Move to the next line
        printf("\n");
    }

    return 0;
}