/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_short.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:10:49 by jvelasco          #+#    #+#             */
/*   Updated: 2022/11/16 17:25:50 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	short_small_list(t_queue *q)
{
	t_node		*newnode;

	while (!is_order_list(q))
	{
		newnode = q->tail;
		if (newnode->value < newnode->prev->value)
		{
			ft_printf("rra\n");
			shift_down(q);
		}
		else
		{
			ft_printf("sa\n");
			swap(q);
		}
	}
	return (0);
}

int	short_list(t_queue *q, t_queue *q2, t_checker *checker)
{
	t_node	*newnode;

	checker->booleano = 0;
	while (q->tail->prev != NULL)
	{
		newnode = q->tail;
		checker_small_numbers(checker, q, newnode->value);
		if (checker->small_num == checker->middle_number -1
			|| (checker->small_num != 0 && checker->last_number != 0))
			shift_list_a(q, checker);
		else
		{
			if (is_order_list(q) == 1 && checker->booleano != 1)
				return (0);
			else if (checker->last_number == 0 && checker->small_num != 0
				&& checker->booleano == 1)
				shift_list_a(q, checker);
			else
				move_stack_a(q, q2, checker);
		}
	}
	return (0);
}

void	move_stack_a(t_queue *q, t_queue *q2, t_checker *checker)
{
	if (checker->last_number == 0 && checker->small_num == 1)
	{
		swap(q);
		ft_printf("sa\n");
	}
	else
	{
		ft_printf("pb\n");
		push_node(q, q2);
		if (checker->last_number == 0 && checker->small_num == 0)
		{
			if (checker->booleano == 1)
			{
				swap(q2);
				ft_printf("sb\n");
				checker->booleano = 0;
			}
		}
		else
			checker->booleano = 1;
		checker->middle_number--;
	}
}
