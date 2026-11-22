/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdlib.h>


static int compare_numbers(Dlist *a, Dlist *b)
{
    Dlist *p = a;
    Dlist *q = b;
    int countA = 0;
    int countB = 0;

   // Count digits in the first number 
    while (p != NULL)
    {
        countA++;
        p = p->next;
    }

    // Count digits in the second number 
    while (q != NULL)
    {
        countB++;
        q = q->next;
    }

    // Compare the number of digits 
    if (countA > countB)
        return 1;

    if (countA < countB)
        return -1;

    // Compare digits from left to right 
    p = a;
    q = b;

    while (p != NULL && q != NULL)
    {
        if (p->data > q->data)
            return 1;

        if (p->data < q->data)
            return -1;

        p = p->next;
        q = q->next;
    }

    return 0;
}

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{
	// Definition goes here 
	 Dlist *temp1, *temp2;
    Dlist *headRem = NULL, *tailRem = NULL;
    Dlist *headQ = NULL, *tailQ = NULL;
    Dlist *temp;
    int quotientDigit;

    (void)tail1;

    *headR = NULL;

    if (*head1 == NULL || *head2 == NULL)
        return FAILURE;

    // Check whether divisor is zero 
    temp2 = *head2;

    while (temp2 != NULL && temp2->data == 0)
        temp2 = temp2->next;

    if (temp2 == NULL)
        return FAILURE;

    temp1 = *head1;

    // Process dividend one digit at a time 
    while (temp1 != NULL)
    {
        if (insert_at_last(&headRem, &tailRem,
                           temp1->data) == FAILURE)
            return FAILURE;

        // Remove leading zeros from remainder 
        while (headRem != NULL &&
               headRem->data == 0 &&
               headRem->next != NULL)
        {
            temp = headRem;
            headRem = headRem->next;
            headRem->prev = NULL;
            free(temp);
        }

        quotientDigit = 0;

        // Subtract divisor until remainder is smaller 
        while (compare_numbers(headRem, *head2) >= 0)
        {
            Dlist *p = tailRem;
            Dlist *q = *tail2;
            int borrow = 0;

            while (p != NULL)
            {
                int sub = p->data - borrow;

                if (q != NULL)
                {
                    sub -= q->data;
                    q = q->prev;
                }

                if (sub < 0)
                {
                    sub += 10;
                    borrow = 1;
                }
                else
                {
                    borrow = 0;
                }

                p->data = sub;
                p = p->prev;
            }

            // Update the remainder's tail and remove leading zeros 
            while (headRem != NULL &&
                   headRem->data == 0 &&
                   headRem->next != NULL)
            {
                temp = headRem;
                headRem = headRem->next;
                headRem->prev = NULL;
                free(temp);
            }

            tailRem = headRem;

            while (tailRem != NULL && tailRem->next != NULL)
                tailRem = tailRem->next;

            quotientDigit++;
        }

        if (insert_at_last(&headQ, &tailQ,
                           quotientDigit) == FAILURE)
            return FAILURE;

        temp1 = temp1->next;
    }

    // Remove leading zeros from quotient 
    while (headQ != NULL &&
           headQ->data == 0 &&
           headQ->next != NULL)
    {
        temp = headQ;
        headQ = headQ->next;
        headQ->prev = NULL;
        free(temp);
    }

    *headR = headQ;

    // Free temporary remainder list 
    while (headRem != NULL)
    {
        temp = headRem;
        headRem = headRem->next;
        free(temp);
    }

    (void)tail2;

    return SUCCESS;

}
