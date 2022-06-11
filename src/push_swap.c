#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_queue		s1;
	t_queue		s2;

	init_queue(&s1);
	init_queue(&s2);
	if (check_int(argc, argv, &s1) == 0)
		printf("error");
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
