#include "monty.h"

/**
 * myOpen_file - opens file
 * @myFile_name: file namz
 * Return: nothing
 */

void myOpen_file(char *myFile_name)
{
	FILE *file_desc = fopen(myFile_name, "r");

	if (myFile_name == NULL || file_desc == NULL)
		hundle_error(2, myFile_name);

	myRead_file(file_desc);
	fclose(file_desc);
}


/**
 * myRead_file - reads file
 * @file_desc: ptr file descriptor
 * Return: notjing
 */

void myRead_file(FILE *file_desc)
{
	int line_number, forme = 0;
	char *buff = NULL;
	size_t longeur = 0;

	for (line_number = 1; getline(&buff, &longeur, file_desc) != -1; line_number++)
	{
		forme = myParse_line(buff, line_number, forme);
	}
	free(buff);
}


/**
 * myParse_line - Separates lines to tokens
 *functions to call
 * @buff: ligne from  file
 * @line_number: line nbr
 * @forme:  stockage de forme
 * Return: 0 if opcode is stack, 1 ifnot
 */

int myParse_line(char *buff, int line_number, int forme)
{
	char *opcode, *valeur;
	const char *delimiteur = "\n ";

	if (buff == NULL)
		hundle_error(4);

	opcode = strtok(buff, delimiteur);
	if (opcode == NULL)
		return (forme);
	valeur = strtok(NULL, delimiteur);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	trouver_maFonc(opcode, valeur, line_number, forme);
	return (forme);
}

/**
 * trouver_maFonc - find the targeted funct
 * @opcode: opcode
 * @valeur: arg of opcode
 * @forme:  storage forme. If 0 Nodes will enter stack.
 * @ligne_nbr: line number
 * if 1 node is entered as queue
 * Return: noting
 */
void trouver_maFonc(char *opcode, char *valeur, int ligne_nbr, int forme)
{
	int k;
	int refrencee;

	instruction_t myfuncts[] = {
		{"push", ajout_toStack},
		{"pall", display_stack},
		{"pint", display_top},
		{"pop", removeTop},
		{"nop", nop},
		{"swap", exchangeNodes},
		{"add", AddNodes},
		{"sub", SubNodes},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (refrencee = 1, k = 0; myfuncts[k].opcode != NULL; k++)
	{
		if (strcmp(opcode, myfuncts[k].opcode) == 0)
		{
			appel_fonc(myfuncts[k].f, opcode, valeur, ligne_nbr, forme);
			refrencee = 0;
		}
	}
	if (refrencee == 1)
		hundle_error(3, ligne_nbr, opcode);
}


/**
 * appel_fonc - Calls finct
 * @fonct: Ptr to funct to be called
 * @opcd: string equivaut a the opcode
 * @valeur: string equivaut a a numeric valeur
 * @ligne_nbr: line number for the instruct
 * @forme: forme specifier. If 0 Nodes are entered as stack
 * if 1 nodes is entered as a queue
 */
void appel_fonc(op_func fonct, char *opcd, char *valeur, int ligne_nbr, int forme)
{
	stack_t *node;
	int refrencee;
	int k;

	refrencee = 1;
	if (strcmp(opcd, "push") == 0)
	{
		if (valeur != NULL && valeur[0] == '-')
		{
			valeur = valeur + 1;
			refrencee = -1;
		}
		if (valeur == NULL)
			hundle_error(5, ligne_nbr);
		for (k = 0; valeur[k] != '\0'; k++)
		{
			if (isdigit(valeur[k]) == 0)
				hundle_error(5, ligne_nbr);
		}
		node = creerNode(atoi(valeur) * refrencee);
		if (forme == 0)
			fonct(&node, ligne_nbr);
		if (forme == 1)
			ajout_toqueue(&node, ligne_nbr);
	}
	else
		fonct(&Head, ligne_nbr);
}
