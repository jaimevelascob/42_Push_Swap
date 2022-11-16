/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:44:05 by jvelasco          #+#    #+#             */
/*   Updated: 2022/11/16 17:55:27 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**cpy(int count, char **new, char const *s, char c);
static int	ft_count(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		count;

	count = 0;
	if (!s)
		return (0);
	count = ft_count(s, c);
	new = malloc(sizeof(char *) * (count + 1));
	if (!new)
		return (0);
	new = cpy(count, new, s, c);
	return (new);
}

static int	ft_count(char const *s, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (i);
}

static char	**cpy(int count, char **new, char const *s, char c)
{
	int	j;
	int	i;
	int	start;
	int	lencountword;

	i = 0;
	j = 0;
	while (j < count)
	{
		lencountword = 0;
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i++])
			lencountword += 1;
		while (s[i] == c && s[i])
			i++;
		new[j] = ft_substr(s, start, lencountword);
		j++;
	}
	new[j] = 0;
	return (new);
}
