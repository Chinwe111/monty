#include "monty.h"
/**
 * func_pint - prints the top
 * @head: a pointer to the stack
 * @line_number: the line of the opcode being executed
 * Return: no return
*/

void func_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
