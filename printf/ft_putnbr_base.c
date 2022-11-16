/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:14:28 by jvelasco          #+#    #+#             */
/*   Updated: 2022/11/16 17:45:05 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long num, char *base)
{
	int		i;
	int		len;

	len = ft_strlen(base);
	i = 0;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= (unsigned long long)len)
		i += ft_putnbr_base(num / len, base);
	ft_putchar(base[(num % len)]);
	i += 1;
	return (i);
}
