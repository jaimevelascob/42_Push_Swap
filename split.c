#include "inc/push_swap.h"

char	*add_char(char newchar, char *oldstr, int size)
{
	char	*newstr;
	newstr = malloc(size+1);

	if (size == 1)
	{
		newstr[0] = newchar;
		newstr[1] = '\0';
		return newstr;
	}
	int i = 0;
	while(oldstr[i])
		newstr[i++] = oldstr[i];
	newstr[i++] = newchar;
	newstr[i] = '\0';
	free(oldstr);
	return newstr;
}


void	next_array(t_checker *checker)
{
	checker->size = 1;
	checker->next++;
	checker->pos++;
}

char	**pass_arguments(char **str, t_checker *checker)
{
	char **newstr;

	checker->size = 1;
	checker->next = 0;
	checker->pos = 0;
	newstr = malloc(sizeof(char*)*501);
	while(str[1][checker->pos])
	{
		while (str[1][checker->pos] <= '9' && str[1][checker->pos] >= '0')
			newstr[checker->next] = add_char(str[1][checker->pos++], newstr[checker->next], checker->size++);
		if (str[1][checker->pos] == ' ' && (str[1][checker->pos+1] <= '9' && str[1][checker->pos+1] >= '0'))
			next_array(checker);
		else if (str[1][checker->pos] == '\0')
			break;
		else
		{
			free_array(newstr, checker);
			newstr = NULL;
			return (newstr);
		}
	}
	return newstr;
}

void	free_array(char **str, t_checker *checker)
{

	int i = 0;
	while(i <= checker->next)
	{
		free(str[i++]);
	}
	free(str);
}

