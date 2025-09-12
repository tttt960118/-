#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 0};

    int n = get_int("Enter a number to search for (1, 2, 3, 4, 0): ");
    for (int i = 0; i < 5; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found number %d at index %i\n", numbers[i], i);
            return 0;
        }
        
    }
    printf("Number not found in the array.\n");
    return 1; // Return an error code if the number is not found
}