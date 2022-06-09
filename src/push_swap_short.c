#include "../inc/push_swap.h"

int	short_list(t_queue *q, t_queue *q2, int middle_number)
{
	t_checker	checker;
	t_node		*newnode;

	while (q->head != NULL)
	{
		newnode = q->tail;
		checker_num(&checker, q, newnode->value);
		if (checker.small_num == 1)
		{
			if (checker.number > middle_number / 2)
			{
				while (checker.number++ < middle_number)
					shift_down(q);
			}
			else
			{
				while (checker.number-- > 0)
					shift_up(q);
			}
		}
		else
			push_node(q, q2);
	}
	return (0);
}

