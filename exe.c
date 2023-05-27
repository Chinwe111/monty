#include "monty.h"
/**
* execute - executes the opcode
* @head: head linked list - stack
* @line_number: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **head, unsigned int line_number,
		FILE *file)
{
	instruction_t opst[] = {
				{"push", func_push}, {"pall", func_pall}, {"pint", func_pint},
				{"pop", func_pop},
				{"swap", func_swap},
				{"add", func_add},
				{"nop", func_nop},
				{"sub", func_sub},
				{"div", func_div},
				{"mul", func_mul},
				{"mod", func_mod},
				{"pchar", func_pchar},
				{"pstr", func_pstr},
				{"rotl", func_rotl},
				{"rotr", func_rotr},
				{"queue", func_queue},
				{"stack", func_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(head, line_number);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(file);
		free(content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	return (1);
}
