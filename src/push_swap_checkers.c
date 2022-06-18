#include "../inc/push_swap.h"

// buscar el numero mas pequeño

int	checker_num_big(t_checker *checker, t_queue *q, int media)
{
	t_node	*newnode;
	static int call=1;
	int i;

	i = 0;
	newnode = q->tail;
	/* recalcular media */
	while (newnode != NULL)
	{
		//if (newnode->value > media && checker.media != 0) 
		printf("media :%d\n", media);
		if (newnode->value <= media) 
			return (media);
		newnode = newnode->prev;
	}
	call++;
	media += media / 5;
	return (media);
}
int	checker_num(t_checker *checker, t_queue *q, int num, int middle_number)
{
	t_node	*newnode;
	int array[middle_number];

	newnode = q->tail;
	checker->small_num = 0;
	checker->number = -1;
	checker->last_number = 0;
	/* conseguir un numero menor que last_number y mayor qe small_num */
	while (newnode != NULL)
	{
		checker->number++;
		/* printf("$ %d- %d- %d %d\n", newnode->value, num, checker->last_number, checker->small_num); */
		if (newnode->value > num && newnode->value < array[checker->last_number])
		{
			checker->last_number = checker->number;
		}
		else if (newnode->value < num) 
		{
			/* printf("-> %d %d\n", num, checker->small_num); */
			checker->last_number = checker->small_num;
			checker->small_num = checker->number;
			num = newnode->value;
			/* printf("-> %d %d\n", num, checker->small_num); */
		}
		array[checker->number] = newnode->value;
		newnode = newnode->prev;
	}
	checker->number = checker->last_number;
	return (1);
}

int	checker_last_num(t_queue *q, int num, t_checker *checker)
{
	t_node *newnode;
	int position;

	newnode = q->tail;
	position = -1;
	checker->last_number = 0;
	if (newnode == NULL)
		return -1;
	while (newnode != NULL)
	{
		position++;
		if (num < newnode->value)
		{
			checker->last_number = position;
			num = newnode->value;
		}	
		newnode = newnode->prev;
	}
	return (0);

}
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
	return (1);
}

long	check_int(int argc, char **argv, t_queue *q, int *media)
{
	static long	z;
	int	size = argc;
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
		*media += z;
	}
	*media /= size -1;
	return (1);
}
