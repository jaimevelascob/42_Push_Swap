#include "../inc/push_swap.h"

int	fill_array(char **newstr, char **str, t_checker *checker)
{
	while ((str[1][checker->pos] <= '9' && str[1][checker->pos] >= '0')
		|| (str[1][checker->pos] <= 'z' && str[1][checker->pos] >= 'a'))
	{
		checker->space = 0;
		newstr[checker->next] = add_char(str[1][checker->pos++],
				newstr[checker->next], checker->size++, checker);
	}
	if ((str[1][checker->pos] == ' '
		&& (str[1][checker->pos + 1] <= '9' && str[1][checker->pos + 1] >= '0'))
		|| (str[1][checker->pos] == ' '
		&& (str[1][checker->pos + 1] <= 'z' && str[1][checker->pos + 1] >= 'a'))
		|| (str[1][checker->pos] == ' ' && str[1][checker->pos + 1] == '-'))
	{
		next_array(checker);
		checker->negative_number = 1;
	}
	else if (str[1][checker->pos] == '-'
		&& (str[1][checker->pos + 1] <= '9' && str[1][checker->pos + 1] >= '0'))
	{
		checker->negative_number = 0;
		checker->pos++;
	}
	else
		return (0);
	return (1);
}

char	**pass_arguments(char **str, t_checker *checker)
{
	char	**newstr;

	init_checkers(checker);
	newstr = malloc(sizeof(char *) * 501);
	while (str[1][checker->pos])
	{
		if (str[1][checker->pos + 1] == '\0'
				&& (str[1][checker->pos] == ' ' || str[1][checker->pos] == '-'))
		{
			if (checker->space == 1)
				checker->next--;
			free_array(newstr, checker);
			newstr = NULL;
			return (newstr);
		}
		else if (str[1][checker->pos] == '\0')
			break ;
		else
			checker->error_val = fill_array(newstr, str, checker);
	}
	return (newstr);
}

void	free_array(char **str, t_checker *checker)
{
	int	i;

	i = 0;
	while (i <= checker->next)
		free(str[i++]);
	free(str);
}

long	check_int_array(int argc, char **argv, t_queue *q, t_checker *checker)
{
	static long		z;
	const int		size = argc;

	while (argc >= 0)
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
		argc--;
	}
	checker->media /= size + 1;
	return (1);
}
