/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_big_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:10:24 by jvelasco          #+#    #+#             */
/*   Updated: 2022/11/16 17:23:57 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	short_list_big(t_queue *q, t_queue *q2, t_checker *checker)
{
	t_node		*newnode;

	checker->middle_number_b = 0;
	checker->bool_media = 0;
	while (q->tail != NULL)
	{
		newnode = q->tail;
		while (checker->bool_media == 0)
			*checker = checker_num_big(checker, q);
		move_value(q, q2, checker, newnode->real_val);
		checker->bool_media = 0;
	}
	checker->booleano = 0;
	while (q2->tail != NULL)
	{
		newnode = q2->tail;
		checker_bigger_nums(q2, newnode->real_val, checker);
		if (checker->last_number != 0 && checker->small_num != 0)
			shift_list_b(q2, checker);
		else
			push_a(q, q2, checker);
	}
	return (0);
}

void	move_value(t_queue *q, t_queue *q2, t_checker *checker, int value)
{
	if (value <= checker->media)
	{
		push_node(q, q2);
		ft_printf("pb\n");
		checker->middle_number_b++;
		checker->middle_number--;
	}
	else
	{
		*checker = checker_shift(q, checker);
		if (checker->l_media_number < checker->f_media_number)
		{
			ft_printf("rra\n");
			shift_down(q);
		}
		else
		{
			ft_printf("ra\n");
			shift_up(q);
		}
	}
}

void	push_a(t_queue *q, t_queue *q2, t_checker *checker)
{
	if (checker->small_num == 0 && checker->booleano == 1)
	{
		ft_printf("pa\n");
		push_node(q2, q);
		ft_printf("sa\n");
		swap(q);
		checker->booleano = 0;
		checker->middle_number_b--;
	}
	else if (checker->small_num == 0)
	{
		ft_printf("pa\n");
		push_node(q2, q);
		checker->middle_number_b--;
	}
	else if (checker->last_number == 0 && checker->booleano == 1)
		shift_list_b(q2, checker);
	else if (checker->last_number == 0)
	{
		ft_printf("pa\n");
		push_node(q2, q);
		checker->booleano = 1;
		checker->middle_number_b--;
	}
}
