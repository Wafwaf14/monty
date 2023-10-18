#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdlib.h>

#define INSTRUCTIONS
	{
		{"push", push},
		{"pall", pall},
		{
			NULL,NULL
		}
	}
void push(stack_t **stack, unsigned int line_cnt);
void pall(stack_t **stack, unsigned int line_cnt);

#endif 
