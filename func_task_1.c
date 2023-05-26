#include "monty.h"
/**
 * func_push - adds an element to the stack
 * @head: a pointer to the stack
 * @line_number: the line of the opcode being executed
 *
 * Return: no return
 */

void func_push(stack_t **head, unsigned int line_number)
{
	int i, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	i = atoi(bus.arg);
	if (bus.ln == 0)
		addnode(head, i);
	else
		addqueue(head, i);
}

/**
 * func_pall - prints the stack
 * @head: a pointer to the stack
 * @line_number: the line of the opcode being executed
 * Return: no return
*/
void func_pall(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
