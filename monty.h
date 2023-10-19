#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct Jag_stack_s - doubly linked list representation of a stack
 * @n: integer
 * @prev: points previous element of the stack
 * @next: points next element of the stack
 *
 * Description: doubly linked list node structure
 */
typedef struct Jag_stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct Jag_globals - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 * Description: doubly linked list node structure
 */
typedef struct Jag_globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct Jag_bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct Jag_bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct Jag_instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 */
typedef struct Jag_instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t vglo;

/* opcode_instructuions*/
void Jag__push(stack_t **stack, unsigned int line_number);
void Jag__pall(stack_t **stack, unsigned int line_number);
void Jag__pint(stack_t **doubly, unsigned int cline);
void Jag__pop(stack_t **doubly, unsigned int cline);
void Jag__swap(stack_t **doubly, unsigned int cline);
void Jag__queue(stack_t **doubly, unsigned int cline);
void Jag__stack(stack_t **doubly, unsigned int cline);
void Jag__add(stack_t **doubly, unsigned int cline);
void Jag__nop(stack_t **doubly, unsigned int cline);
void Jag__sub(stack_t **doubly, unsigned int cline);
void Jag__div(stack_t **doubly, unsigned int cline);
void Jag__mul(stack_t **doubly, unsigned int cline);
void Jag__mod(stack_t **doubly, unsigned int cline);
void Jag__pchar(stack_t **doubly, unsigned int cline);
void Jag__pstr(stack_t **doubly, unsigned int cline);
void Jag__rotl(stack_t **doubly, unsigned int cline);
void Jag__rotr(stack_t **doubly, unsigned int cline);

/*get function*/
void (*Jag_get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/*imported functions*/
int Jag__sch(char *s, char c);
char *Jag__strtoky(char *s, char *d);
void *Jag__realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *Jag__calloc(unsigned int nmemb, unsigned int size);
int Jag__strcmp(char *s1, char *s2);

/* doubly linked list functions */
stack_t *Jag_add_dnodeint_end(stack_t **head, const int n);
stack_t *Jag_add_dnodeint(stack_t **head, const int n);
void Jag_free_dlistint(stack_t *head);

/* main */
void Jag_free_vglo(void);

#endif /* __MONTY_H__ */

