#include "monty.h"


/**
 * ajout_toStack - Add node to stackk
 * @updated_node: Ptr to new node
 * @integ: Int equiv to line number of the opcode
 */
void ajout_toStack(stack_t **updated_node, __attribute__((unused))unsigned int integ)
{
	stack_t *tempo;

	if (updated_node == NULL || *updated_node == NULL)
		exit(EXIT_FAILURE);
	if (Head == NULL)
	{
		Head = *updated_node;
		return;
	}
	tempo = Head;
	Head = *updated_node;
	Head->next = tempo;
	tempo->prev = Head;
}


/**
 * display_stack - display nodes in the stackk
 * @stackk: Pointr to a pointer pointing  top node
 * @ligne_nbr: line number of  the opcode
 */
void display_stack(stack_t **stackk, unsigned int ligne_nbr)
{	
	stack_t *tempo;

	(void) ligne_nbr;
	if (stackk == NULL)
		exit(EXIT_FAILURE);
	tempo = *stackk;
	while (tempo != NULL)
	{
		printf("%d\n", tempo->n);
		tempo = tempo->next;
	}
}

/**
 * display_top - Prints the top node of the stackk.
 * @stackk: Pointr to a pointer pointing  top node
 * @ligne_nbr: Int equiv to line number of the opcode
 */
void display_top(stack_t **stackk, unsigned int ligne_nbr)
{
	if (stackk == NULL || *stackk == NULL)
		other_errors(6, ligne_nbr);
	printf("%d\n", (*stackk)->n);
}
