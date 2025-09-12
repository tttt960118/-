#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    int age;
} person;

int main(void)
{
    person people[3];
    people[0].name = "Alice";
    people[0].age = 30;
    people[1].name = "Bob";
    people[1].age = 25;
    people[2].name = "Charlie";
    people[2].age = 35;

    string search_name = get_string("Enter name to search: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, search_name) == 0)
        {
            printf("Found %s, age %d\n", people[i].name, people[i].age);
            return 0;
        }
    }
    printf("Name not found.\n");
    return 1;
}