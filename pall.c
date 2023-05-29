#include "monty.h"
/**
 * func_pall - prints the stack
 * @head: a pointer to the stack
 * @line_num: the line of the opcode being executed
 * Return: no return
*/

void func_pall(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	(void)line_num;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
