#include "monty.h"
/**
 * func_pop - prints the top
 * @head: a pointer to the stack
 * @line_num: the line of the opcode being executed
 * Return: no return
*/

void func_pop(stack_t **head, unsigned int line_num)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
