/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{
	/* Definition goes here */
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;

	Dlist *tailR = NULL;

	int count1 = 0, count2 = 0;
	int negative = 0;
	int borrow = 0;

	 // Count the digits in Number 1
	while (temp1 != NULL)
	{
		count1++;
		temp1 = temp1->prev;
	}

	 // Count the digits in Number 2
	while (temp2 != NULL)
	{
		count2++;
		temp2 = temp2->prev;
	}
	
    int comparison = 0;

	//  Numbers with more digits have the greater magnitude,assuming the input lists contain no leading zeros.
	if (count1 > count2)
	{
		comparison = 1;
	}
	else if (count1 < count2)
	{
		comparison = -1;
	}
	else
	{
		// If both numbers have the same number of digits,compare them from the most significant digit
		temp1 = *head1;
		temp2 = *head2;

		while (temp1 != NULL && temp2 != NULL)
		{
			// Number 1 is larger at the first differing digit
		    if (temp1->data > temp2->data)
			{
				comparison = 1;
				break;
			}
			// Number 2 is larger at the first differing digit
			else if (temp1->data < temp2->data)
			{
				comparison = -1;
				break;
			}

			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		
	}

	// If both numbers are equal, the result is zero
	if (comparison == 0)
	{
		insert_at_first(headR, &tailR, 0);

		return SUCCESS;
	}

    if (comparison < 0)
	{
		Dlist *tempHead = *head1;
		Dlist *tempTail = *tail1;

		*head1 = *head2;
		*tail1 = *tail2;

		*head2 = tempHead;
		*tail2 = tempTail;

		negative = 1;
	}

	// Start subtracting from the rightmost digits
	temp1 = *tail1;
	temp2 = *tail2;

	while (temp1 != NULL)
	{

	   // Get the current digit of the larger number
	   int digit1 = temp1->data;
	   // If the smaller number has no digit at this position use zero
	   int digit2 = 0;	

	   if (temp2 != NULL)
	   {
		  digit2 = temp2->data;
	   }

	   int difference = digit1 - digit2 - borrow;

	   // If the difference is negative, borrow from the next higher digit by adding 10 to this digit
	   if (difference < 0)
	   {
		  difference = difference + 10;
		  borrow = 1;
	   }
	   else
	   {
		  borrow = 0;
	   }

	   // Store the result digit at the front of the result list
	   if(insert_at_first(headR, &tailR, difference) == FAILURE)
	   {
		  return FAILURE;
	   }

	   // Move left to the next digit of Number 1
	   temp1 = temp1->prev;

	   // Move left in Number 2 if digits remain
	   if (temp2 != NULL)
	   {
          temp2 = temp2->prev;
	   }
	}

	// Print a minus sign if the original Number 2 was larger
	if (negative)
	{
		printf("-");
	}

	return SUCCESS;
}
