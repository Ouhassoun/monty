#include "monty.h"

/**
 * Jag_get_opcodes - selects the correct opcode to perform
 * @opc: opcode passed
 * Return: pointer to the function that executes the opcode
 */
void (*Jag_get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", Jag__push},
		{"pall", Jag__pall},
		{"pint", Jag__pint},
		{"pop", Jag__pop},
		{"swap", Jag__swap},
		{"add", Jag__add},
		{"nop", Jag__nop},
		{"sub", Jag__sub},
		{"div", Jag__div},
		{"mul", Jag__mul},
		{"mod", Jag__mod},
		{"pchar", Jag__pchar},
		{"pstr", Jag__pstr},
		{"rotl", Jag__rotl},
		{"rotr", Jag__rotr},
		{"stack", Jag__stack},
		{"queue", Jag__queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (Jag__strcmp(instruct[i].opcode, opc) == 0)
			break;
	}

	return (instruct[i].f);
}

