#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void pint(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !(*stack))
	{
		fprint(stderr,"l%d: cant pint, stack empty \n", line_cnt);
		exit(EXIT_FAILURE);
	}
	printf("%d \n",(*stack)->n);
}
