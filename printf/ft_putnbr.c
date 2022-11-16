/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:27:38 by jvelasco          #+#    #+#             */
/*   Updated: 2021/11/26 12:51:57 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_division(va_list arg)
{
	char	*str;
	int		ncount;

	ncount = 0;
	str = ft_itoa(va_arg(arg, int));
	ncount += ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (ncount);
}
