#include "../inc/push_swap.h"

int	check_duplicate_int(t_queue *q, int number)
{
	t_node	*newnode;

	newnode = q->head;
	while (newnode != NULL)
	{
		if (newnode->value == number)
			return (0);
		newnode = newnode->next;
	}
	free(newnode);
	return (1);
}

int	check_int(int argc, char **argv, t_queue *q)
{
	int	z;

	z = 0;
	while (argc-- > 1)
	{
		z = atoi(argv[argc]);
		if (z != 0)
		{
			if (check_duplicate_int(q, z) == 0)
				return (0);
			enqueue(q, z);
		}
		else
			return (0);
	}
	return (1);
}
