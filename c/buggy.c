#include <stdio.h>


void print_column(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#\n");
    }
}

int get_int(const char *prompt)
{
    int n;
    printf("%s", prompt);
    scanf("%d", &n);
    return n;
}

int main (void)
{
    int h = get_int("Height: ");
    print_column(h);
}
