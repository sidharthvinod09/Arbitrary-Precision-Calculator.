#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

int insert_at_first(Dlist **headR, Dlist **tailR,int digit)
{
   Dlist *newNode = malloc (sizeof(Dlist));

   if (newNode == NULL)
   {
      return FAILURE;
   }

   newNode->data = digit;

   newNode->prev = NULL;

   newNode->next = *headR;

   if (*headR == NULL)
   {
      *headR = newNode;
      *tailR = newNode;
   }
   else
   {
      (*headR)->prev = newNode;
      *headR = newNode;
   }

}