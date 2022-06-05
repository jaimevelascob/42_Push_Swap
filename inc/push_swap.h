#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stdio.h"
# include "stdlib.h"
# include "push_swap.h"
# include "unistd.h"

typedef struct node {
	int			value;
	struct node	*prev;
	struct node	*next;
}	t_node;

typedef struct queue {
	t_node	*head;
	t_node	*tail;
}	t_queue;

/* push_swap */
int		enqueue(t_queue *q, int value);
int		dequeue(t_queue *q);
void	init_queue(t_queue *q);
int		print_list(t_queue *q);
/* push_swap_controls */
int		swap(t_queue *q);
int		push_node(t_queue *n_delete, t_queue *n_push);
int		shift_up(t_queue *n);
int		shift_down(t_queue *n);
#endif
