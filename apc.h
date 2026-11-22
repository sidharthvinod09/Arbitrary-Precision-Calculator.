#ifndef APC_H
#define APC_H
#include <stddef.h>
#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
int insert_at_last(Dlist **head1, Dlist **tail1, int data);

int insert_at_first(Dlist **headR, Dlist **tailR,int digit);

void print_list(Dlist *head);

static int compare_numbers(Dlist *a, Dlist *b);

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);

#endif
