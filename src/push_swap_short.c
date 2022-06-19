#include "../inc/push_swap.h"

void	shift_list(t_queue *q, t_checker checker, int middle_number)
{
	if (checker.small_num <= middle_number/2)
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

void	shift_list_b(t_queue *q, t_checker checker, int middle_number)
{
	if (checker.small_num <= middle_number/2)
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
	while(newnode->next != NULL)
	{
		if (newnode->value > newnode->next->value)
			newnode = newnode->next;
		else
			return (0);
	}
	return (1);
}

int	short_list_big(t_queue *q, t_queue *q2, int middle_number, int media)
{
	t_checker	checker;
	t_node		*newnode;
	static int			booleano;
	static int			middle_number_b;

	checker.bool_media = 0;
	while (q->tail != NULL)
	{
		newnode = q->tail;
		while (checker.bool_media == 0)
			media = checker_num_big(&checker, q, media);
		if (newnode->value <= media)
		{
			push_node(q, q2);
			printf("pb\n");
			middle_number_b++;
			middle_number--;
		}
		else
		{
			checker_media_nums(q, &checker, media);
			if (checker.l_media_number < checker.f_media_number)
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
		checker.bool_media = 0;
	}
	booleano = 0;
	while (q2->tail != NULL)
	{
		newnode = q2->tail;
		checker_last_num(q2, newnode->value, &checker, middle_number_b);
		if (checker.last_number != 0 && checker.small_num != 0)
		{
			shift_list_b(q2, checker, middle_number_b);
		}
		else
		{
			if (checker.small_num == 0 && booleano == 1)
			{
				printf("pa\n");
				push_node(q2, q);
				printf("sa\n");
				swap(q);
				booleano = 0;
				middle_number_b--;
			}
			else if (checker.small_num == 0)
			{
				printf("pa\n");
				push_node(q2, q);
				middle_number_b--;
			}
			else if (checker.last_number == 0 && booleano == 1)
				shift_list_b(q2, checker, middle_number_b);
			else if (checker.last_number == 0)
			{
				printf("pa\n");
				push_node(q2, q);
				booleano = 1;
				middle_number_b--;
			}
		}
	}
	return (0);
}


/* para 3 */

// 5 > <49
int	short_list(t_queue *q, t_queue *q2, int middle_number, int media)
{
	t_checker		checker;
	t_node			*newnode;

	checker.booleano = 0;
	while (q->tail->prev != NULL)
	{
		newnode = q->tail;
		checker_num(&checker, q, newnode->value, middle_number - 1);
		if (checker.small_num == middle_number -1 ||  (checker.small_num != 0  && checker.last_number != 0))
			shift_list(q, checker, middle_number);
		else
		{
			if (is_order_list(q) == 1)
				return (0);
			else
				middle_number = move_stack_a(q, q2, &checker, middle_number);
		}
	}
	return (0);
}

int	move_stack_a(t_queue *q, t_queue *q2, t_checker *checker, int middle_number)
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
		middle_number--;
	}
	return middle_number;
}
