#include "../inc/push_swap.h"

char	*add_str(char *newstr, char newchar, t_checker *checker, int size)
{
	newstr = malloc(size + 2);
	newstr[0] = '-';
	newstr[1] = newchar;
	newstr[2] = '\0';
	checker->size++;
	return (newstr);
}

char	*add_char(char newchar, char *oldstr, int size, t_checker *checker)
{
	char	*newstr;
	int		i;

	if (size == 1 && checker->negative_number == 0)
	{
		newstr = add_str(newstr, newchar, checker, size);
		return (newstr);
	}
	newstr = malloc(size + 1);
	if (size == 1)
	{
		newstr[0] = newchar;
		newstr[1] = '\0';
		return (newstr);
	}
	i = 0;
	while (oldstr[i])
		newstr[i++] = oldstr[i];
	newstr[i++] = newchar;
	newstr[i] = '\0';
	free(oldstr);
	return (newstr);
}

void	next_array(t_checker *checker)
{
	checker->space = 1;
	checker->size = 1;
	checker->next++;
	checker->pos++;
}

void	init_checkers(t_checker *checker)
{
	checker->size = 1;
	checker->space = 0;
	checker->negative_number = 1;
	checker->next = 0;
	checker->pos = 0;
}
