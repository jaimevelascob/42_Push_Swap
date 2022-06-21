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
	return (1);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		oper;
	long	res;

	i = 0;
	oper = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '
		|| str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		i++;
		oper *= -1;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	if ((res * oper) > 2147483647 || (res * oper) < -2147483648)
		return (2147483649);
	return (res * oper);
}
