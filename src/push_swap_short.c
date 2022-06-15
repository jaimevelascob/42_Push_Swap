#include "../inc/push_swap.h"

int	shift_list(t_queue *q, t_queue *q2, t_checker checker, int middle_number, int booleano)
{
	int z = checker.small_num;
	int middle = middle_number;
		/* printf("ac: %d %d %d\n", middle_number / 2, checker.small_num, checker.last_number); */
	
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
	return booleano;
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

int	short_list(t_queue *q, t_queue *q2, int middle_number)
{
	t_checker	checker;
	t_node		*newnode;
	static int			booleano;

	while (q->tail->prev != NULL)
	{
		newnode = q->tail;
		checker_num(&checker, q, newnode->value, middle_number - 1);
		/* printf("smal -> %d, last -> %d midle: %d\n", checker.small_num, checker.last_number, middle_number); */
		/* print_list(q); */
		if (checker.small_num != 0 && checker.last_number != 0)
		{
			booleano = shift_list(q, q2, checker, middle_number, booleano);

		}
		else
		{
			int z = is_order_list(q); 
			if (z == 1)
				return (0);
			else if (checker.last_number == 0 && checker.small_num == 1)
			{
				swap(q);
				printf("sa\n");
			}
			else if (checker.last_number == 0 && checker.small_num == 0)
			{
				printf("/> pb\n");
				push_node(q, q2);
				middle_number--;
			}
			else if (checker.last_number == 0 && checker.small_num != middle_number-1)
			{
				printf("-> pb\n");
				push_node(q, q2);
				booleano = 1;
				middle_number--;
			}
			else
			{
				printf("pb\n");
				push_node(q, q2);
				if (booleano == 1)
				{
					swap(q2);
					printf("sb\n");
					booleano = 0;
				}
				middle_number--;
			}
		}
	}
	return (0);
}
