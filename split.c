#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

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

int pass_arguments(char **str)
{
	char **newstr;
	static int	size = 1;
	static int	next;
	
	newstr = malloc(sizeof(char*)*3);
	while(*str[1])
	{
		while (*str[1] <= '9' && *str[1] >= '0')
			newstr[next] = add_char(*str[1]++, newstr[next], size++);
		if (*str[1] == ' ')
		{
			size = 1;
			next++;
			*str[1]++;
		}
		/* else */
		/* 	return (0); */
	}
	printf("%s\n", newstr[next]);
	free(newstr);
	return 1;
}

int	main(int argc, char **argv)
{
	pass_arguments(argv);
	return 0;
}
