#include "monty.h"

/**
 * Jag__queue - sets format of data to queue
 * @doubly: head of linked list
 * @cline: line number
 */
void Jag__queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 0;
}

/**
 * Jag__stack - sets format of data to stack
 * @doubly: linked list head
 * @cline: line number
 */
void Jag__stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 1;
}

