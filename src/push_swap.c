#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_queue		s1;
	t_queue		s2;
	t_checker	checker;
	long		error_val;
	int			media[0];

	checker.media = 0;
	init_queue(&s1);
	init_queue(&s2);
	error_val = check_int(argc, argv, &s1, &checker);
	if (error_val == 2147483649)
		printf("Error\n");
	else if (argc == 1)
		return (0);
	else
	{
		checker.middle_number = argc - 1;
		if (argc < 5)
			short_small_list(&s1);
		else if (argc > 49 && argc < 250)
		{
			checker.media = checker.media / 2;
			short_list_big(&s1, &s2, &checker);
		}
		else if (argc > 250)
		{
			checker.media = checker.media / 3;
			short_list_big(&s1, &s2, &checker);
		}
		else
			short_list(&s1, &s2, &checker);
		free_list(&s1, &s2);
	}
	print_list(&s1);
	return (0);
}
