#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_queue		s1;
	t_queue		s2;
	t_checker	checker;
	char		**str;
	long		error_val;

	checker.media = 0;
	init_queue(&s1);
	init_queue(&s2);
	if (argc <= 2)
	{
		str = pass_arguments(argv, &checker);
		if (!str)
			return 0;
		else
			error_val = check_int_array(checker.next, str, &s1, &checker);
		free_array(str, &checker);
		print_list(&s1);
		return (0);
		checker.middle_number = checker.next + 1;
	}
	else
	{
		error_val = check_int(argc, argv, &s1, &checker);
		checker.middle_number = argc - 1;
	}
		printf("adios %ld\n", error_val);
	if (error_val == 2147483649)
	{
		print_list(&s1);
		printf("Error\n");
	}
	else
		init_media(&checker, &s1, &s2);
	return (0);
}

int	fill_list(int argc, t_checker *checker, char **argv, t_queue *s1)
{
	char	**str;

	if (argc <= 2)
	{
		str = pass_arguments(argv, checker);
		if (!str)
			return 0;
		else
			checker->error_val = check_int_array(checker->next, str, s1, checker);
		free_array(str, checker);
		checker->middle_number = checker->next + 1;
	}
	else
	{
		checker->error_val = check_int(argc, argv, s1, checker);
		checker->middle_number = argc - 1;
	}
}

void init_media(t_checker *checker, t_queue *s1, t_queue *s2)
{
	if (checker->middle_number < 4)
		short_small_list(s1);
	else if (checker->middle_number > 49 && checker->middle_number < 250)
	{
		checker->media = checker->media / 2;
		short_list_big(s1, s2, checker);
	}
	else if (checker->middle_number > 250)
	{
		checker->media = checker->media / 3;
		short_list_big(s1, s2, checker);
	}
	else
		short_list(s1, s2, checker);
	free_list(s1, s2);
	print_list(s1);
}
