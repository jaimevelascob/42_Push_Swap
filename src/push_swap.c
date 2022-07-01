#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_queue		s1;
	t_queue		s2;
	t_checker	checker;
	char		**str;

	checker.media = 0;
	init_queue(&s1);
	init_queue(&s2);
	if (argc <= 2)
	{
		if (argc != 1 && !check_errors(argv[1]))
			printf("Error\n");
		return (0);
	}
	if (!fill_list(argc, &checker, argv, &s1))
		printf("Error\n");
	else if (checker.error_val == 2147483649)
	{
		print_list(&s1);
		printf("Error\n");
	}
	else
		init_media(&checker, &s1, &s2);
	return (0);
}

void	valor_error(t_error *error, int a, int b)
{
	error->space = a;
	error->minus = b;
}

int	check_errors(char *argv)
{
	t_error	error;

	valor_error(&error, 1, 0);
	while (*argv)
	{
		if (is_digit(*argv))
			valor_error(&error, 0, 0);
		else if (is_space(*argv))
		{
			if (!check_space(&error))
				return (0);
		}
		else if (is_minus(*argv))
		{
			if (!check_minus(&error))
				return (0);
		}
		else
			return (0);
		argv++;
	}
	if (error.space == 1 || error.minus == 1)
		return (0);
	return (1);
}

int	fill_list(int argc, t_checker *checker, char **argv, t_queue *s1)
{
	char	**str;

	if (argc < 2)
	{
		checker->min = 0;
		if (!check_errors(argv[1]))
			return (0);
		str = pass_arguments(argv, checker);
		if (!str)
			return (0);
		else
			checker->error_val = check_int(checker->next + 1,
					str, s1, checker);
		free_array(str, checker);
		checker->middle_number = checker->next + 1;
	}
	else
	{
		checker->min = 1;
		checker->error_val = check_int(argc, argv, s1, checker);
		checker->middle_number = argc - 1;
	}
	return (1);
}

void	init_media(t_checker *checker, t_queue *s1, t_queue *s2)
{
	if (checker->middle_number < 4)
		short_small_list(s1);
	else if (checker->middle_number > 49 && checker->middle_number < 250)
	{
		checker->media = checker->middle_number / 5;
		short_list_big(s1, s2, checker);
	}
	else if (checker->middle_number > 250)
	{
		checker->media = checker->middle_number / 11;
		short_list_big(s1, s2, checker);
	}
	else
		short_list(s1, s2, checker);
	free_list(s1, s2);
	print_list(s1);
}
