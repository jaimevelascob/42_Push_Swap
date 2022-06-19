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
	int		media;
	int		middle_number;
	int		middle_number_b;
	int		booleano;
	int		bool_media;
	int		number;
	int		last_number;
	int		small_num;
	int		f_media_number;
	int		l_media_number;
}	t_checker;
/* push_swap_init */
int		enqueue(t_queue *q, int value);
int		dequeue(t_queue *q);
void	init_queue(t_queue *q);
int		print_list(t_queue *q);
t_checker	reset_checkers(t_checker *checker);
/* push_swap_controls */
void	free_list(t_queue *q, t_queue *q2);
int		swap(t_queue *q);
int		push_node(t_queue *n_delete, t_queue *n_push);
int		shift_up(t_queue *n);
int		shift_down(t_queue *n);
/* push_swap_checkers */
t_checker	checker_shift(t_queue *q, t_checker *checker);
void	checker_small_numbers(t_checker *checker, t_queue *q, int num);
t_checker	checker_num_big(t_checker *checker, t_queue *q);
void	checker_bigger_nums(t_queue *q, int num, t_checker *checker);
long	check_int(int argc, char **argv, t_queue *q, t_checker *checker);
/* push_swap_short */
int		short_small_list(t_queue *q);
void	move_stack_a(t_queue *q, t_queue *q2, t_checker *checker);
int		short_list(t_queue *q, t_queue *q2, t_checker *checker);
int		short_list_big(t_queue *q, t_queue *q2, t_checker *checker);
void	shift_list_a(t_queue *q, t_checker *checker);
/* ft_atoi */
long	ft_atoi(const char *str);
int		check_duplicate_int(t_queue *q, int number);

#endif
