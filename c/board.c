#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (void)
{
    float input;
    scanf("%.2f",&input);
    if (scanf("%f", &input) != 1)
    {
        printf("Error\n");
        return 1;
    }
    if (input<0.00 || input>5.20)
    {
        printf("Error\n");
        return 1;
    }
    int n = 1;
    float f = 0.50;
    while (f<input)
    {
        n++;
        f += 1.00/(n+1);
    }
    printf("%d\n",n);
    return 0;

}