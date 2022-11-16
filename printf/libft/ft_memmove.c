/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:21:51 by jvelasco          #+#    #+#             */
/*   Updated: 2022/11/16 17:51:09 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	int	i;

	i = 0;
	if (!str1 && !str2)
		return (0);
	if (str1 > str2)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(str1 + i) = *(char *)(str2 + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(str1 + i) = *(char *)(str2 + i);
			i++;
		}
	}
	return (str1);
}
