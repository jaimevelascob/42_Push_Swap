#include "../inc/push_swap.h"

/* swap last position */
int	swap(t_queue *q)
{
	int	temp;

	if (q->head == NULL || q->head->next == NULL)
		return (0);
	temp = q->tail->value;
	q->tail->value = q->tail->prev->value;
	q->tail->prev->value = temp;
	return (0);
}

int	push_node(t_queue *n_delete, t_queue *n_push)
{
	int		temp;
	t_node	*newnode;

	if (n_delete->tail == NULL)
		return (0);
	newnode = n_delete->tail;
	temp = n_delete->tail->value;
	if (n_delete->tail == n_delete->head)
	{
		n_delete->tail->value = 0;
		n_delete->tail = NULL;
		n_delete->head = NULL;
	}
	else
	{
		n_delete->tail = n_delete->tail->prev;
		n_delete->tail->next = NULL;
	}
	free(newnode);
	enqueue(n_push, temp);
	return (0);
}

/* Shift up all elements of stack a by 1. */
int	shift_up(t_queue *n)
{
	t_node	*newnode;
	t_node	*d_node;

	if (n->head == NULL || n->head->next == NULL)
		return (0);
	newnode = malloc(sizeof(t_node));
	d_node = n->tail;
	newnode->value = n->tail->value;
	n->tail->prev->next = NULL;
	n->tail = n->tail->prev;
	free(d_node);
	newnode->next = n->head;
	newnode->prev = NULL;
	n->head->prev = newnode;
	n->head = newnode;
	return (1);
}

/* Shift down all elements of stack a by 1. */
int	shift_down(t_queue *n)
{
	int		temp;
	t_node	*d_node;

	if (n->head == NULL || n->head->next == NULL)
		return (0);
	d_node = n->head;
	temp = n->head->value;
	n->head->next->prev = NULL;
	n->head = n->head->next;
	free(d_node);
	enqueue(n, temp);
	return (0);
}
