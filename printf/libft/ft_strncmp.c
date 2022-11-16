/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:25:03 by jvelasco          #+#    #+#             */
/*   Updated: 2022/11/16 17:53:19 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*news1;
	unsigned char	*news2;

	i = 0;
	if (n == 0)
		return (0);
	news1 = (unsigned char *)s1;
	news2 = (unsigned char *)s2;
	while (news1[i] == news2[i] && news1[i] != '\0'
		&& news2[i] != '\0' && i < n)
		i++;
	if (i != n)
		return (news1[i] - news2[i]);
	return (0);
}
