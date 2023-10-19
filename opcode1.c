#include "monty.h"

/**
 * Jag__add - Adds the top two values of a stack_t linked list.
 * @doubly: head of the linked list
 * @cline: line number
 * Description: The result is stored in the second value node
 * from the top and the top value  is removed.
 */
void Jag__add(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		Jag_free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	Jag__pop(doubly, cline);
}

/**
 * Jag__nop - doesn't do anything
 * @doubly: linked list head
 * @cline: line number
 */
void Jag__nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}
/**
 * Jag__sub - Subtracts 2nd value
 * @head: the head node
 * @cline: the line number
 * Description: The result is stored in the second value
 */

void Jag__sub(stack_t **head, unsigned int cline)
{
	int m = 0;
	stack_t *current;

	current = *head;

	for (; current != NULL; current = current->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		Jag_free_vglo();
		exit(EXIT_FAILURE);
	}

	current = (*head)->next;
	current->n -= (*head)->n;
	Jag__pop(head, cline);
}

/**
 *Jag__div - Divides 2nd value from the top
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */

void Jag__div(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", cline);
		Jag_free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		Jag_free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n /= (*doubly)->n;
	Jag__pop(doubly, cline);
}

/**
 *Jag__mul - Multiplies 2nd value from the top of stack_t linked list
 * @head: the head node
 * @cline: the line number
 * info:The result is stored in the 2nd value node
 * from the top and top value removed.
 */

void Jag__mul(stack_t **head, unsigned int cline)
{
	int m = 0;
	stack_t *current;

	current = *head;

	for (; current != NULL; current = current->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", cline);
		Jag_free_vglo();
		exit(EXIT_FAILURE);
	}

	current = (*head)->next;
	current->n *= (*head)->n;
	Jag__pop(head, cline);
}

