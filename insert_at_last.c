#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

int insert_at_last (Dlist **head, Dlist **tail, int data)
{
    Dlist *newNode = malloc (sizeof(Dlist));

    if (newNode == NULL)
    {
        return FAILURE;
    }

    newNode->data = data;

    newNode->prev = *tail;

    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;

        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;

        *tail = newNode;
    }

    return SUCCESS;
}