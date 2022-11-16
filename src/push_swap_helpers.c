/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:10:42 by jvelasco          #+#    #+#             */
/*   Updated: 2022/11/16 17:24:52 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	shift_list_a(t_queue *q, t_checker *checker)
{
	if (checker->small_num <= checker->middle_number / 2)
	{
		shift_up(q);
		ft_printf("ra\n");
	}
	else
	{
		shift_down(q);
		ft_printf("rra\n");
	}
}

void	shift_list_b(t_queue *q, t_checker *checker)
{
	if (checker->small_num <= checker->middle_number_b / 2)
	{
		shift_up(q);
		ft_printf("rb\n");
	}
	else
	{
		shift_down(q);
		ft_printf("rrb\n");
	}
}

int	is_order_list(t_queue *q)
{
	t_node	*newnode;

	newnode = q->head;
	while (newnode->next != NULL)
	{
		if (newnode->value > newnode->next->value)
			newnode = newnode->next;
		else
			return (0);
	}
	return (1);
}
