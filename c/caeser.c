#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    // Check if the user provided exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }
    string key = argv[1];
    if (!only_digits(key))
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }
    // Convert the command-line argument to an integer
    int number = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        // Check if the character is an uppercase letter
        if (isupper(plaintext[i]))
        {
            // Shift the character by the key value, wrapping around if necessary
            plaintext[i] = ((plaintext[i] - 'A' + number) % 26) + 'A';
        }
        // Check if the character is a lowercase letter
        else if (islower(plaintext[i]))
        {
            // Shift the character by the key value, wrapping around if necessary
            plaintext[i] = ((plaintext[i] - 'a' + number) % 26) + 'a';
        }
        else
        {
            // Non-alphabetic characters remain unchanged
            plaintext[i] = plaintext[i];
        }
    }
    printf("ciphertext: %s\n", plaintext);

    // Print the number
}

bool only_digits(string s)
{
    // Check if each character in the string is a digit
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
