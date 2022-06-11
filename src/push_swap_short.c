#include "../inc/push_swap.h"

void	shift_list(t_queue *q, t_checker checker, int middle_number)
{
	if (checker.number == 1)
	{
		swap(q);
		printf("sa\n");
	}
	else if (checker.number > middle_number / 2)
	{
		while (checker.number++ < middle_number)
		{
			shift_down(q);
			printf("rra\n");
		}
	}
	else
	{
		while (checker.number-- > 0)
		{
			shift_up(q);
			printf("ra\n");
		}
	}
}

int	short_list(t_queue *q, t_queue *q2, int middle_number)
{
	t_checker	checker;
	t_node		*newnode;

	while (q->tail->prev != NULL)
	{
		newnode = q->tail;
		checker_num(&checker, q, newnode->value);
		if (checker.small_num == 1)
			shift_list(q, checker, middle_number);
		else
		{
			printf("pb\n");
			push_node(q, q2);
		}
	}
	return (0);
}
