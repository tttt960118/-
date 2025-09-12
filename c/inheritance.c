#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct person
{
    char alleles[2];
    struct person *parents[2];
} person;

person *create_family(int generations);
void print_family(person *p, int generations);
void free_family(person *p);
char random_allele();

int main(void)
{
    int generations = 3;
    person *p = create_family(3);
    print_family(p, 0);
    free_family(p);
}
person *create_family(int generations)
{
    person *p = malloc(sizeof(person));

    if (generations > 1)
    {
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);
        p->parents[0] = parent0;
        p->parents[1] = parent1;
        p->alleles[0] = parent0->alleles[rand() % 2];
        p->alleles[1] = parent1->alleles[rand() % 2];
    }else
    {
        p->parents[0] = NULL;
        p->parents[1] = NULL;
        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
    }
    return p;
}
char random_allele()
{   
    int r = rand()%3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }   
}
    void free_family(person *p)
{
    if (p == NULL)
    {
        return;
    }
    free_family(p->parents[0]);
    free_family(p->parents[1]);
    free(p);
}
void print_family(person *p, int generations)
{
    if (p == NULL)
    {
        return;
    }
    for (int i = 0; i < generations*2; i++)
    {
        printf("  ");
    }
   if (generations == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generations,p->alleles[0], p->alleles[1]);
    }
    else if (generations == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generations,p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generations - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generations,p->alleles[0], p->alleles[1]);
    }
    print_family(p->parents[0], generations + 1);
    print_family(p->parents[1], generations + 1);
}
