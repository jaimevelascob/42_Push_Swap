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
	}
	free(newnode);
	printf("\n");
	return (0);
}

int	main(void)
{
	t_queue	s1;
	t_queue	s2;

	init_queue(&s1);
	init_queue(&s2);
	int t = 4;
	while (t-- > 1)
		enqueue(&s1, t);
	print_list(&s1);
	t = 4;
	swap(&s1);
	while (t-- > 1)
		printf("%d", dequeue(&s1));
	return (0);
}
