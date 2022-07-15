#include "monty.h"

/**
 * add_element - adds a new node at the beginning
 * of a stack_t
 * @head: head of the stack
 * @n: value of the element
 * Return: the address of the new element
 */
stack_t *add_element(stack_t **head, const int n)
{
        stack_t *new;
        stack_t *h;

        new = malloc(sizeof(stack_t));
        if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(*head);
                exit(EXIT_FAILURE);
	}

	new->n = n;
        new->prev = NULL;
        h = *head;

	if (h != NULL)
        {
                while (h->prev != NULL)
                        h = h->prev;
        }

        new->next = h;

        if (h != NULL)
		h->prev = new;

        *head = new;

        return (new);
}

/**
 * p_stack_t - prints all the elements of a dlistint_t list
 * @h: head of list
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

/**
 * delete_element - deletes the node at index of a
 * stack_t linked list
 *
 * @head: head of the list
 * @index: index of the new node
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_element(stack_t **head, unsigned int index)
{
	stack_t *h1;
	stack_t *h2;
	unsigned int i;

	h1 = *head;

	if (h1 != NULL)
		while (h1->prev != NULL)
			h1 = h1->prev;

	i = 0;

	while (h1 != NULL)
	{
		if (i == index)
		{
			if (i == 0)
			{
				*head = h1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				h2->next = h1->next;

				if (h1->next != NULL)
					h1->next->prev = h2;
			}

			free(h1);
			return (1);
		}
		h2 = h1;
		h1 = h1->next;
		i++;
	}

	return (-1);
}

/**
 * add_element_end - adds a new node at the end of a stack_t list
 * @head: head of linked list
 * @n: constant integer
 * Return: address of new element or NULL if it failed
 */
stack_t *add_element_end(stack_t **head, const int n)
{
	stack_t *h;
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = NULL;

	h = *head;

	if (h != NULL)
	{
		while (h->next != NULL)
			h = h->next;
		h->next = new;
	}
	else
	{
		*head = new;
	}

	new->prev = h;

	return (new);
}

/**
 * free_stack - Frees the memory allocated to a doubly linked list.
 * @head: Pointer to the HEAD of the list.
 * Return: Void.
 */
void free_stack(stack_t *head)
{
	stack_t *current, *temp;

	current = head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
