#include "../inc/push_swap.h"
// hacer que vaya con un 0

int	main(int argc, char **argv)
{
	t_queue		s1;
	t_queue		s2;
	long		error_val;
	int			media[0];

	*media = 0;
	init_queue(&s1);
	init_queue(&s2);
	printf("media : %d\n", *media);
	error_val = check_int(argc, argv, &s1, media);
	printf("media : %d\n", *media);
	if (error_val == 2147483649)
		printf("Error\n");
	else if (argc == 1)
		return (0);
	else
	{
		short_list(&s1, &s2, argc - 1, *media);
		free_list(&s1, &s2);
	}
	print_list(&s1);
	return (0);
}
