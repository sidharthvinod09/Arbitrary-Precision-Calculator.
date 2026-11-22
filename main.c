/**************************************************************************************************************************************************************
*Title		: Arbitrary Precision Calculator
*name       : Sidhart vinod
***************************************************************************************************************************************************************/
#include "apc.h"
#include<stdio.h>

int main(int argc, char *argv[])
{
   
	// Argument Validation
    if (argc != 4)
    {
       printf("Usage: ./a.out operand1 operator operand2\n");
       return FAILURE;
    }

	/* Declare the pointers */
	Dlist *head1 = NULL, *tail1 = NULL;
	Dlist *head2 = NULL, *tail2 = NULL;
	Dlist *headR = NULL;

	char option, operator;

	int i = 0,num = 0;

	// Create Dlist and store value of operand 1
	while (argv[1][i] != '\0')
	{
        num = argv[1][i] - '0';
		
		insert_at_last(&head1,&tail1,num);

		i++;
	}

	i = 0;
    
	// Create Dlist and store  value of operand 2
    while (argv[3][i] != '\0')
	{
        num = argv[3][i] - '0';
		
		insert_at_last(&head2,&tail2,num);

		i++;
	}

	// Initialize operator
	operator = argv[2][0];


		switch (operator)
		{
			case '+':
				/* call the function to perform the addition operation */
				if (addition(&head1, &tail1, &head2, &tail2, &headR) == SUCCESS)
                {
                   printf("Result: ");
                   print_list(headR);
                }
                else
                {    
                   printf("Addition failed\n");
                }
                break;

			case '-':	
				/* call the function to perform the subtraction operation */
				if (subtraction(&head1, &tail1, &head2, &tail2, &headR) == SUCCESS)
                {
                  // printf("Result: ");
                   print_list(headR);
                }
                else
                {    
                   printf("Subtraction failed\n");
                }
                break;
			case '*':	
				/* call the function to perform the multiplication operation */
				if (multiplication(&head1, &tail1, &head2, &tail2, &headR) == SUCCESS)
                {
                   print_list(headR);
                }
                else
                {    
                   printf("Multiplication failed\n");
                }
				break;
			case '/':	
				/* call the function to perform the division operation */
				if (division(&head1, &tail1, &head2, &tail2, &headR) == SUCCESS)
                {
                  // printf("Result: ");
                   print_list(headR);
                }
                else
                {    
                   printf("Division failed\n");
                }
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}

	return 0;
}
