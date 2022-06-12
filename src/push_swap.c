#include "../inc/push_swap.h"
// hacer que vaya con un 0

int	main(int argc, char **argv)
{
	t_queue		s1;
	t_queue		s2;
	long		error_val;

	init_queue(&s1);
	init_queue(&s2);
	error_val = check_int(argc, argv, &s1);
	if (error_val == 2147483649)
		printf("Error\n");
	else if (argc == 1)
		return (0);
	else
	{
		short_list(&s1, &s2, argc - 1);
		free_list(&s1, &s2);
	}
	print_list(&s1);
	return (0);
}
