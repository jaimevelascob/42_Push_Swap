/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:39:25 by jvelasco          #+#    #+#             */
/*   Updated: 2022/11/16 17:53:37 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*news;
	size_t			i;
	size_t			size;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (size > len)
		size = len;
	news = malloc(size + 1);
	if (!news)
		return (0);
	if (start >= (unsigned int)ft_strlen(s) || start > len)
	{
		free(news);
		return (ft_strdup(""));
	}
	i = 0;
	while (s[i + start] && i < len)
	{
		news[i] = s[start + i];
		i++;
	}
	news[i] = 0;
	return (news);
}
