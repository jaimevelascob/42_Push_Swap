#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"

typedef struct	node {
	int value;
	struct node	*prev;
	struct node	*next;
}	node;

typedef struct {
	node *head;
	node *tail;
}   queue;

void  init_queue(queue *q)
{
	q->head = NULL;
	q->tail = NULL;
}

/* push */
int enqueue(queue *q, int value)
{
	node * newnode = malloc(sizeof(node));
	if (newnode == NULL) return 0;
	newnode->value = value;
	newnode->next = NULL;

	if (q->tail != NULL)
	{
	  newnode->prev = q->tail;
	  q->tail->next = newnode;
	}
	q->tail = newnode;
	if (q->head == NULL)
	  q->head = newnode;

	return 0;
}
/* swap last position */
int swap(queue *q)
{
	int	temp;
	/* if only is one */
	if (q->head == NULL || q->head->next == NULL)
	  return 0;
	temp = q->tail->value;
	q->tail->value = q->tail->prev->value;
	q->tail->prev->value = temp;
	return 0;
}

int dequeue(queue *q)
{
	if (q->head == NULL) return 0;
	node *tmp = q->head;
	int result = tmp->value;
	q->head = q->head->next;

	if (q->head == NULL)
	  q->tail = NULL;
	free(tmp);
	return result;
}

int main()
{
	queue s1, s2;

	init_queue(&s1);
	init_queue(&s2);

	int t = 5;
	while(t-- > 1)
		enqueue(&s2, t);
	swap(&s2);
	return 0;
}
