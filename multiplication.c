/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/


#include "apc.h"
#include <stdlib.h>

int multiplication(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   Dlist **headR)
{
    Dlist *temp1, *temp2;
    Dlist *headP = NULL, *tailP = NULL;
    Dlist *headSum = NULL, *tailR = NULL;

    int carry, product, digit;
    int zeros = 0;

    *headR = NULL;

    // Handle multiplication by zero 
    if ((*head1)->data == 0 && (*head1)->next == NULL)
    {
        return insert_at_first(headR, &tailR, 0);
    }

    if ((*head2)->data == 0 && (*head2)->next == NULL)
    {
        return insert_at_first(headR, &tailR, 0);
    }

    // Start from the last digit of Number 2 
    temp2 = *tail2;

    while (temp2 != NULL)
    {
        temp1 = *tail1;
        carry = 0;

        headP = NULL;
        tailP = NULL;

        // Multiply Number 1 by the current digit 
        while (temp1 != NULL)
        {
            product = (temp1->data * temp2->data) + carry;
            digit = product % 10;
            carry = product / 10;

            if (insert_at_first(&headP, &tailP, digit) == FAILURE)
                return FAILURE;

            temp1 = temp1->prev;
        }

        // Store remaining carry 
        while (carry > 0)
        {
            digit = carry % 10;
            carry /= 10;

            if (insert_at_first(&headP, &tailP, digit) == FAILURE)
                return FAILURE;
        }

        // Append zeros for the place value 
        for (int i = 0; i < zeros; i++)
        {
            if (insert_at_last(&headP, &tailP, 0) == FAILURE)
                return FAILURE;
        }

        // First partial product becomes the result 
        if (*headR == NULL)
        {
            *headR = headP;
            tailR = tailP;

            headP = NULL;
            tailP = NULL;
        }
        else
        {
            headSum = NULL;

            if (addition(headR, &tailR,
                         &headP, &tailP,
                         &headSum) == FAILURE)
            {
                return FAILURE;
            }

            // Find the end of the new sum 
            tailR = headSum;

            while (tailR != NULL && tailR->next != NULL)
            {
                tailR = tailR->next;
            }

            *headR = headSum;

            headP = NULL;
            tailP = NULL;
        }

        zeros++;
        temp2 = temp2->prev;
    }

    // Remove leading zeros 
    while (*headR != NULL &&
           (*headR)->data == 0 &&
           (*headR)->next != NULL)
    {
        Dlist *temp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(temp);
    }

    return SUCCESS;
}
