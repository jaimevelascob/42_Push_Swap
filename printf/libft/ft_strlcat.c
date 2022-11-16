/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:23:01 by jvelasco          #+#    #+#             */
/*   Updated: 2022/11/16 17:52:56 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	y;

	i = 0;
	x = ft_strlen(dest);
	y = ft_strlen(src);
	j = x;
	if (size < x)
		return (y + size);
	else
	{
		while (src[i] && (j + 1 < size))
		{
			dest[j] = src[i];
			j++;
			i++;
		}
		dest[j] = '\0';
		return (x + y);
	}
}
