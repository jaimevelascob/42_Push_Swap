#include "../inc/push_swap.h"

void	shift_list_a(t_queue *q, t_checker *checker)
{
	if (checker->small_num <= checker->middle_number / 2)
	{
		shift_up(q);
		printf("ra\n");
	}
	else
	{
		shift_down(q);
		printf("rra\n");
	}
}

void	shift_list_b(t_queue *q, t_checker *checker)
{
	if (checker->small_num <= checker->middle_number_b / 2)
	{
		shift_up(q);
		printf("rb\n");
	}
	else
	{
		shift_down(q);
		printf("rrb\n");
	}
}

int	is_order_list(t_queue *q)
{
	t_node	*newnode;

	newnode = q->head;
	while (newnode->next != NULL)
	{
		if (newnode->value > newnode->next->value)
			newnode = newnode->next;
		else
			return (0);
	}
	return (1);
}

int	short_list_big(t_queue *q, t_queue *q2, t_checker *checker)
{
	t_node		*newnode;

	checker->middle_number_b = 0;
	checker->bool_media = 0;
	while (q->tail != NULL)
	{
		newnode = q->tail;
		while (checker->bool_media == 0)
			*checker = checker_num_big(checker, q);
		if (newnode->value <= checker->media)
		{
			push_node(q, q2);
			printf("pb\n");
			checker->middle_number_b++;
			checker->middle_number--;
		}
		else
		{
			*checker = checker_shift(q, checker);
			if (checker->l_media_number < checker->f_media_number)
			{
				printf("rra\n");
				shift_down(q);
			}
			else
			{
				printf("ra\n");
				shift_up(q);
			}
		}
		checker->bool_media = 0;
	}
	checker->booleano = 0;
	while (q2->tail != NULL)
	{
		newnode = q2->tail;
		checker_bigger_nums(q2, newnode->value, checker);
		if (checker->last_number != 0 && checker->small_num != 0)
			shift_list_b(q2, checker);
		else
		{
			if (checker->small_num == 0 && checker->booleano == 1)
			{
				printf("pa\n");
				push_node(q2, q);
				printf("sa\n");
				swap(q);
				checker->booleano = 0;
				checker->middle_number_b--;
			}
			else if (checker->small_num == 0)
			{
				printf("pa\n");
				push_node(q2, q);
				checker->middle_number_b--;
			}
			else if (checker->last_number == 0 && checker->booleano == 1)
				shift_list_b(q2, checker);
			else if (checker->last_number == 0)
			{
				printf("pa\n");
				push_node(q2, q);
				checker->booleano = 1;
				checker->middle_number_b--;
			}
		}
	}
	return (0);
}

int	short_small_list(t_queue *q)
{
	t_node		*newnode;

	while (!is_order_list(q))
	{
		newnode = q->tail;
		if (newnode->value < newnode->prev->value)
		{
			printf("rra\n");
			shift_down(q);
		}
		else
		{
			printf("sa\n");
			swap(q);
		}
	}
	return (0);
}

int	short_list(t_queue *q, t_queue *q2, t_checker *checker)
{
	t_node			*newnode;

	checker->booleano = 0;
	while (q->tail->prev != NULL)
	{
		newnode = q->tail;
		checker_small_numbers(checker, q, newnode->value);
		if (checker->small_num == checker->middle_number -1
			|| (checker->small_num != 0 && checker->last_number != 0))
			shift_list_a(q, checker);
		else
		{
			if (is_order_list(q) == 1 && checker->booleano != 1)
				return (0);
			else if (checker->last_number == 0 && checker->small_num != 0 && checker->booleano == 1)
				shift_list_a(q, checker);
			else
				move_stack_a(q, q2, checker);
		}
	}
	return (0);
}

void	move_stack_a(t_queue *q, t_queue *q2, t_checker *checker)
{
	if (checker->last_number == 0 && checker->small_num == 1)
	{
		swap(q);
		printf("sa\n");
	}
	else
	{
		printf("pb\n");
		push_node(q, q2);
		if (checker->last_number == 0 && checker->small_num == 0)
		{
			if (checker->booleano == 1)
			{
				swap(q2);
				printf("sb\n");
				checker->booleano = 0;
			}
		}
		else
			checker->booleano = 1;
		checker->middle_number--;
	}
}
