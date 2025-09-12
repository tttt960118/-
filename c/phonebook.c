
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    char name[100];
    char number[100];
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);

    for (int i = 0; name[i] != '\0'; i++)
    {
        if (name[i] == '\n')
        {
            name[i] = '\0';
            break;
        }
    }
    printf("Enter number: ");
    fgets(number, sizeof(number), stdin);
    for (int i = 0; number[i] != '\0'; i++)
    {
        if (number[i] == '\n')
        {
            number[i] = '\0';
            break;
        }
    }

    fprintf(file, "%s,%s\n", name, number);
    fclose(file);
    return 0;
}