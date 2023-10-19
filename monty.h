#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function all gd
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *Head;
typedef void (*op_func)(stack_t **, unsigned int);


void myOpen_file(char *myFile_name);
int myParse_line(char *buff, int line_number, int forme);
void myRead_file(FILE *);
int longueur_char(FILE *);
void trouver_maFonc(char *, char *, int, int);


stack_t *creerNode(int n);
void freeMy_node(void);
void display_stack(stack_t **, unsigned int);
void ajout_toStack(stack_t **, unsigned int);
void ajout_toqueue(stack_t **, unsigned int);

void appel_fonc(op_func, char *, char *, int, int);

void display_top(stack_t **, unsigned int);
void removeTop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void exchangeNodes(stack_t **, unsigned int);


void AddNodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);



void hundle_error(int erreur_code, ...);
void other_errors(int erreur_code, ...);

#endif