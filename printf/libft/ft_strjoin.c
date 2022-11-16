/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:02:42 by jvelasco          #+#    #+#             */
/*   Updated: 2022/11/16 17:52:51 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	news = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!news)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		news[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		news[i] = s2[j];
		i++;
		j++;
	}
	news[i] = 0;
	return (news);
}
