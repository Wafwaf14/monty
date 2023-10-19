#include "monty.h"
stack_t *Head = NULL;

/**
 * main - dashboard
 * @argc: arguments counter
 * @argv: array of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	myOpen_file(argv[1]);
	freeMy_node();
	return (0);
}

/**
 * creerNode - Creates Node.
 * @n: Nbr to go inside the Node.
 * Return: sucess  ptr to Node. ifnot NULL
 */
stack_t *creerNode(int n)
{
	stack_t *myNode;

	myNode = malloc(sizeof(stack_t));
	if (myNode == NULL)
		hundle_error(4);
	myNode->next = NULL;
	myNode->prev = NULL;
	myNode->n = n;
	return (myNode);
}

/**
 * freeMy_node - libere all nodes in stack.
 */
void freeMy_node(void)
{
	stack_t *tempo;

	if (Head == NULL)
		return;

	while (Head != NULL)
	{
		tempo = Head;
		Head = Head->next;
		free(tempo);
	}
}


/**
 * ajout_toqueue - Adds Node to queu
 * @nouv_node: Ptr to new myNode
 * @lgne_nbr: line nbr of the opcode
 */
void ajout_toqueue(stack_t **nouv_node, __attribute__((unused))unsigned int lgne_nbr)
{
	stack_t *tempo;

	if (nouv_node == NULL || *nouv_node == NULL)
		exit(EXIT_FAILURE);
	if (Head == NULL)
	{
		Head = *nouv_node;
		return;
	}
	tempo = Head;
	while (tempo->next != NULL)
		tempo = tempo->next;

	tempo->next = *nouv_node;
	(*nouv_node)->prev = tempo;

}
