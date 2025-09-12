#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = get_int("Number: "); // Assign a number to the node
        n->next = NULL;                  // Point to the previous head

        if (list == NULL)
        {
            list = n; // Update the head to the new node
        }
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL )
                {
                    ptr->next = n;       // Insert before the current node// Link the new node to the next node
                    break;
                }
            }   // Update the head to the new node
        }
    }
        for (node *ptr = list; ptr != NULL; ptr = ptr->next)
        {
            printf("%d\n", ptr->number);
        }
        printf("\n");
    
    return 0;
}