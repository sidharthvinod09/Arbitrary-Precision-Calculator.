#include <stdio.h>
#include "apc.h"

void print_list(Dlist *head)
{
    Dlist *temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }

    printf("\n");
}