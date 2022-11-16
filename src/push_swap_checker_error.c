/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_error.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:10:29 by jvelasco          #+#    #+#             */
/*   Updated: 2022/11/16 17:10:30 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == 32)
		return (1);
	return (0);
}

int	is_minus(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

int	check_space(t_error *error)
{
	if (error->space == 1 || error->minus == 1)
		return (0);
	else
	{
		error->space = 1;
		error->minus = 0;
	}
	return (1);
}

int	check_minus(t_error *error)
{
	if (error->minus == 1)
		return (0);
	else
	{
		error->space = 1;
		error->minus = 1;
	}
	return (1);
}
