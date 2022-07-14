#include <stdio.h>
#include "lists.h"
#include "monty.h"

/**
 * p_stack_t - prints all the elements of a dlistint_t list
 * @h: head of list
 *
 * Return: the number of nodes
 */
size_t p_stack_t(const stack_t *h)
{
	const stack_t *p;
	int i;

	i = 0;
	p = h;
	while (p != NULL)
	{
		printf("%d\n", p->n);
		i++;
		p = p->next;
	}
	return (i);
}
