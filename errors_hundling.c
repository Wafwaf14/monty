#include "monty.h"

/**
 * hundle_error - hundle deffrent errors
 * @erreur_code:error codes to be hundled:
 * 1 user not giving any file
 * 2 file provided cannot opened or read.
 * 3 file with invalid instruction.
 * 4 unable to malloc more memory
 * 5 "push" is not an int.
 * 6 stack empty for pint.
 * 7 stack it empty for pop.
 * 8 stack too short.
 */
void hundle_error(int erreur_code, ...)
{
	va_list argmnts;
	char *opcd;
	int line_nbr;

	va_start(argmnts, erreur_code);
	switch (erreur_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(argmnts, char *));
			break;
		case 3:
			line_nbr = va_arg(argmnts, int);
			opcd = va_arg(argmnts, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_nbr, opcd);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(argmnts, int));
			break;
		default:
			break;
	}
	freeMy_node();
	exit(EXIT_FAILURE);
}

/**
 * other_errors - handles errors.
 * @erreur_code: error codes are the following
 * 6 stack it empty for pint
 * 7 it empty for pop
 * 8 stack is too short for operation
 */
void other_errors(int erreur_code, ...)
{
	va_list argmnts;
	char *opcd;
	int line_nbr;

	va_start(argmnts, erreur_code);
	switch (erreur_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(argmnts, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(argmnts, int));
			break;
		case 8:
			line_nbr = va_arg(argmnts, unsigned int);
			opcd = va_arg(argmnts, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_nbr, opcd);
			break;
		default:
			break;
	}
	freeMy_node();
	exit(EXIT_FAILURE);
}
