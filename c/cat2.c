#include <stdio.h>


char get_char(const char *prompt)
{
    char c;
    printf("%s", prompt);
    // 读取一个字符并丢弃后面的换行符
    scanf(" %c", &c);
    return c;
}
int get_int(const char *prompt)
{
    int n;
    printf("%s", prompt);
    scanf("%d", &n);
    return n;
}

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Meow!\n");
    }

}
int main(void)
{
    int n;
    printf("How many times should I meow? ");
    scanf("%d", &n);
    meow(n);
    return 0;
}