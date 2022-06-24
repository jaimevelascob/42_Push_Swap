#include "../inc/push_swap.h"

t_checker	checker_num_big(t_checker *checker, t_queue *q)
{
	t_node	*newnode;

	newnode = q->tail;
	while (newnode != NULL)
	{
		if (newnode->value <= checker->media)
		{
			checker->bool_media = 1;
			return (*checker);
		}
		newnode = newnode->prev;
	}
	checker->media += checker->media / 5;
	checker->bool_media = 0;
	return (*checker);
}

void	checker_small_numbers(t_checker *checker, t_queue *q, int num)
{
	t_node	*newnode;
	int		*array;

	array = malloc(sizeof(int) * checker->middle_number);
	newnode = q->tail;
	*checker = reset_checkers(checker);
	while (newnode != NULL)
	{
		checker->number++;
		if (newnode->value > num
			&& newnode->value < array[checker->last_number])
			checker->last_number = checker->number;
		else if (newnode->value < num)
		{
			checker->last_number = checker->small_num;
			checker->small_num = checker->number;
			num = newnode->value;
		}
		array[checker->number] = newnode->value;
		newnode = newnode->prev;
	}
	checker->number = checker->last_number;
	free(array);
}

void	checker_bigger_nums(t_queue *q, int num, t_checker *checker)
{
	t_node	*newnode;
	int		*array;

	array = malloc(sizeof(int) * checker->middle_number_b);
	newnode = q->tail;
	*checker = reset_checkers(checker);
	while (newnode != NULL)
	{
		checker->number++;
		if (num > newnode->value
			&& newnode->value > array[checker->last_number])
			checker->last_number = checker->number;
		else if (num < newnode->value)
		{
			checker->last_number = checker->small_num;
			checker->small_num = checker->number;
			num = newnode->value;
		}
		array[checker->number] = newnode->value;
		newnode = newnode->prev;
	}
	free(array);
}

t_checker	checker_shift(t_queue *q, t_checker *checker)
{
	t_node	*newnode;
	int		boolean;
	int		position;

	boolean = 0;
	position = -1;
	newnode = q->tail;
	while (newnode != NULL)
	{
		position++;
		if (newnode->value < checker->media && boolean == 0)
		{
			checker->f_media_number = position;
			boolean = 1;
		}
		else if (newnode->value < checker->media)
			checker->l_media_number = (checker->middle_number - position) - 1;
		newnode = newnode->prev;
	}
	return (*checker);
}

long	check_int(int argc, char **argv, t_queue *q, t_checker *checker)
{
	static long		z;
	const int		size = argc;

	while (argc-- > 1)
	{
		z = ft_atoi(argv[argc]);
		if (z != 2147483649)
		{
			if (check_duplicate_int(q, z) == 0)
				return (2147483649);
			enqueue(q, z);
		}
		else
			return (2147483649);
		checker->media += z;
	}
	checker->media /= size - 1;
	return (1);
}
