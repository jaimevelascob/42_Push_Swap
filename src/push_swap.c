#include "../inc/push_swap.h"

int	checker_num(t_checker *checker, t_queue *q, int num)
{
	t_node	*newnode;

	newnode = q->tail;
	checker->small_num = 0;
	checker->number = -1;
	while (newnode != NULL)
	{
		checker->number++;
		if (newnode->value < num)
		{
			checker->small_num = 1;
			return (1);
		}
		newnode = newnode->prev;
	}
	return (1);
}

int	order(t_queue *q, t_queue *q2, int middle_number)
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

int	main(int argc, char **argv)
{
	t_queue		s1;
	t_queue		s2;

	init_queue(&s1);
	init_queue(&s2);
	if (check_int(argc, argv, &s1) == 0)
		printf("error");
	else
	{
		printf("s1->\n");
		print_list(&s1);
		order(&s1, &s2, argc - 1);
		printf("s2->\n");
		print_list(&s2);
	}
	return (0);
}
