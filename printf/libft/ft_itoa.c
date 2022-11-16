/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:17:28 by jvelasco          #+#    #+#             */
/*   Updated: 2022/11/16 17:49:56 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	divide_numb(long c)
{
	int	count;

	count = 0;
	if (c == 0)
		return (1);
	if (c < 0)
	{
		count++;
		c *= -1;
	}
	while (c > 0)
	{
		count++;
		c /= 10;
	}
	return (count);
}

static char	*fill_array(char *new, long number, long int count)
{
	int	i;

	i = 0;
	if (number < 0)
	{
		new[0] = '-';
		number *= -1;
	}
	if (number == 0)
		new[i] = '0';
	while (number > 0)
	{
		new[count - 1] = (number % 10) + '0';
		number /= 10;
		count--;
		i++;
	}
	return (new);
}

char	*ft_itoa(int n)
{
	char		*new;
	long int	count;
	long		num;

	num = n;
	count = divide_numb(num);
	new = malloc(count + 1);
	if (!new)
		return (0);
	new[count] = '\0';
	new = fill_array(new, num, count);
	return (new);
}
