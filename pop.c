#include "monty.h"
/**
 * func_pop - prints the top
 * @stack: a pointer to the stack
 * @line_number: the current working line number of a Monty bytecodes file
 * Return: no return
*/

void func_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	*stack = h->next;
	free(h);
}
