#include "monty.h"
/**
 * func_pint - prints the top
 * @stack: a pointer to the stack
 * @line_number: the current working line number to the Monty bytecode file
 * Return: no return
*/

void func_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		void line_number;
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
