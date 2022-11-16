/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:13:14 by jvelasco          #+#    #+#             */
/*   Updated: 2021/11/18 17:44:57 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calculate(const char *str, int i, int oper);

int	ft_atoi(const char *str)
{
	int		i;
	int		oper;
	long	res;

	i = 0;
	oper = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		i++;
		oper *= -1;
	}
	else if (str[i] == '+')
		i++;
	res = ft_calculate(str, i, oper);
	return (res);
}

static int	ft_calculate(const char *str, int i, int oper)
{
	long	res;

	res = 0;
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			if ((res * oper) > 2147483647)
				return (-1);
			else if ((res * oper) < -2147483648)
				return (0);
			res = (res * 10) + (str[i++] - '0');
		}
	}
	return (res * oper);
}
