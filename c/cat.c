#include <stdio.h>
#include <cs50.h>

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Meow!\n");
    }   
}

int get_positive_int(const char *prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    } 
    while (n < 1);
    return n;
}


int main(void)
{
    int n = get_positive_int("How many times should I meow? ");
    meow(n);
    return 0;
}