#include <stdio.h>

int main(void)
{
    int scores[3];
    for (int i = 0; i < 3; i++)
    {
        printf("Enter score %d: ", i + 1);
        scanf("%d", &scores[i]);
    }
}