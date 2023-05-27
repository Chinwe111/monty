#include "monty.h"
/**
 * func_pop - prints the top
 * @head: a pointer to the stack
 * @line_number: the line of the opcode being executed
 * Return: no return
*/

void func_pop(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
