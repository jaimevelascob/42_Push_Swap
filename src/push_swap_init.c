#include "../inc/push_swap.h"

void	init_queue(t_queue *q)
{
	q->head = NULL;
	q->tail = NULL;
}

/* push */
int	enqueue(t_queue *q, int value)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (newnode == NULL)
		return (0);
	newnode->value = value;
	newnode->next = NULL;
	if (q->tail != NULL)
	{
		newnode->prev = q->tail;
		q->tail->next = newnode;
	}
	else
		newnode->prev = NULL;
	q->tail = newnode;
	if (q->head == NULL)
		q->head = newnode;
	return (0);
}

int	dequeue(t_queue *q)
{
	int		result;
	t_node	*tmp;

	if (q->head == NULL)
		return (0);
	tmp = q->head;
	result = tmp->value;
	q->head = q->head->next;
	if (q->head == NULL)
		q->tail = NULL;
	free(tmp);
	return (result);
}

int	print_list(t_queue *q)
{
	t_node	*newnode;

	newnode = q->head;
	while (newnode != NULL)
	{
		printf("%d", newnode->value);
		newnode = newnode->next;
		dequeue(q);
	}
	free(newnode);
	return (0);
}