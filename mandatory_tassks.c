#include "monty.h"

/**
 * nop -  nothing.
 * @stackk: Ptr to a ptr pointing to top node stackk
 * @ligne_nbr: Int equival to the number of opcode
 */
void nop(stack_t **stackk, unsigned int ligne_nbr)
{
	(void)stackk;
	(void)ligne_nbr;
}


/**
 * exchangeNodes - Swap top two elements of stackk
 * @stackk: Pointr to a pointer pointing  top node
 * @ligne_nbr: Int equiv the line number of the opcode
 */
void exchangeNodes(stack_t **stackk, unsigned int ligne_nbr)
{
	stack_t *tempo;

	if (stackk == NULL || *stackk == NULL || (*stackk)->next == NULL)
		other_errors(8, ligne_nbr, "swap");
	tempo = (*stackk)->next;
	(*stackk)->next = tempo->next;
	if (tempo->next != NULL)
		tempo->next->prev = *stackk;
	tempo->next = *stackk;
	(*stackk)->prev = tempo;
	tempo->prev = NULL;
	*stackk = tempo;
}

/**
 * AddNodes - Adds the top two elements of the stackk.
 * @stackk: Pointr to a pointer pointing  top node
 * @ligne_nbr: Int equiv the line number of the opcode
 */
void AddNodes(stack_t **stackk, unsigned int ligne_nbr)
{
	int somme;

	if (stackk == NULL || *stackk == NULL || (*stackk)->next == NULL)
		other_errors(8, ligne_nbr, "add");

	(*stackk) = (*stackk)->next;
	somme = (*stackk)->n + (*stackk)->prev->n;
	(*stackk)->n = somme;
	free((*stackk)->prev);
	(*stackk)->prev = NULL;
}

/**
 * removeTop - remove a node to the stackk.
 * @stackk: Pointer to a pointer pointing to top node of the stackk.
 * @ligne_nbr: Int equiv the line number of the opcode
 */
void removeTop(stack_t **stackk, unsigned int ligne_nbr)
{
	stack_t *tempo;

	if (stackk == NULL || *stackk == NULL)
		other_errors(7, ligne_nbr);

	tempo = *stackk;
	*stackk = tempo->next;
	if (*stackk != NULL)
		(*stackk)->prev = NULL;
	free(tempo);
}

/**
 * this is an advanced tassk yahooooooooo more points
 * SubNodes - reduce the top two elements of the stackk.
 * @stackk: Pointr to a pointer pointing  top node
 * @ligne_nbr: Int equiv the line number of the opcode
 */
void SubNodes(stack_t **stackk, unsigned int ligne_nbr)
{
	int somme;

	if (stackk == NULL || *stackk == NULL || (*stackk)->next == NULL)

		other_errors(8, ligne_nbr, "sub");


	(*stackk) = (*stackk)->next;
	somme = (*stackk)->n - (*stackk)->prev->n;
	(*stackk)->n = somme;
	free((*stackk)->prev);
	(*stackk)->prev = NULL;
}

