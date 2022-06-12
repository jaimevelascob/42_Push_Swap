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

typedef struct checker {
	int		number;
	int		small_num;
}	t_checker;
/* push_swap_init */
int		enqueue(t_queue *q, int value);
int		dequeue(t_queue *q);
void	init_queue(t_queue *q);
int		print_list(t_queue *q);
void	free_list(t_queue *q, t_queue *q2);
/* push_swap_controls */
int		swap(t_queue *q);
int		push_node(t_queue *n_delete, t_queue *n_push);
int		shift_up(t_queue *n);
int		shift_down(t_queue *n);
/* push_swap_checkers */
int		checker_num(t_checker *checker, t_queue *q, int num);
long	check_int(int argc, char **argv, t_queue *q);
int		check_duplicate_int(t_queue *q, int number);
/* push_swap_short */
int		short_list(t_queue *q, t_queue *q2, int middle_number);
void	shif_list(t_queue *q, t_checker checker, int middle_number);
long	ft_atoi(const char *str);
#endif
