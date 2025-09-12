#include <cs50.h>
#include <stdio.h>
#include <string.h>

void print_bulb(int bit);

int main (void)
{
    string message = get_string("Enter a message: ");
    int length = strlen(message);
    int section[length][8]; // 8 bits for each character
    for (int i = 0 ; i < length; i++)
    {
        int c = message[i];
        for (int j = 0; j < 8; j++)
        {
            section[i][j] = c % 2;
            c = c / 2;
        }
    }
    for (int k = 0; k < length; k++)
    {
        for (int l = 7; l >= 0; l--)
        {
            print_bulb(section[k][l]);
        }
        printf("\n");
    }
}
void print_bulb(int bit)
{
    if (bit == 1)
    {
        printf("💡");
    }
    else
    {
        printf("🔌");
    }
}
