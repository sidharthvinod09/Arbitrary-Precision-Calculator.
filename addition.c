/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{
	/* Definition goes here */
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	
	// Tail pointer for the result linked list
	Dlist *tailR = NULL;

	// Initially, there is no carry
	int carry = 0;

    // Continue while either number has digits remaining or a carry still needs to be processed
	while (temp1 != NULL || temp2 != NULL || carry != 0)
	{
       int sum = carry;

	   // If Number 1 has a digit, add it to sum and move to the previous digit
       if (temp1 != NULL)
	   {
          sum = sum + temp1->data;
	      temp1 = temp1->prev;
	   }

	    //If Number 2 has a digit, add it to sum and move to the previous digit
	   if (temp2 != NULL)
	   {
		  sum = sum + temp2->data;
		  temp2 = temp2->prev; 
	   }

	   // Extract the current result digit and Calculate the carry for the next position.
	   int digit = sum % 10;
	   carry = sum / 10;

       //Insert the calculated digit at the beginning of the result list to maintain digit order
	   if (insert_at_first(headR, &tailR, digit) == FAILURE)
	   {
		   return FAILURE;
	   }
	   
	}
	
    // Return SUCCESS when addition is completed
	return SUCCESS;
}
