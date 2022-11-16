/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:10:52 by jvelasco          #+#    #+#             */
/*   Updated: 2022/11/16 17:10:52 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	**pass_arguments(char **str, t_checker *checker)
{
	char	**newstr;

	init_checkers(checker);
	newstr = malloc(sizeof(char *) * 501);
	while (str[1][checker->pos])
	{
		while (str[1][checker->pos] <= '9' && str[1][checker->pos] >= '0')
		{
			checker->space = 0;
			newstr[checker->next] = add_char(str[1][checker->pos++],
					newstr[checker->next], checker->size++, checker);
		}
		if (str[1][checker->pos] == ' ')
		{
			next_array(checker);
			checker->negative_number = 1;
		}
		else if (str[1][checker->pos] == '-')
		{
			checker->negative_number = 0;
			checker->pos++;
		}
	}
	return (newstr);
}

void	free_array(char **str, t_checker *checker)
{
	int	i;

	i = 0;
	while (i <= checker->next)
		free(str[i++]);
	free(str);
}

void	give_real_valor(t_queue *q)
{
	t_node	*node_value;
	t_node	*newnode;

	newnode = q->head;
	node_value = q->tail;
	while (newnode->next != NULL)
	{
		if (node_value->value > newnode->value)
			node_value->real_val++;
		else
			newnode->real_val++;
		newnode = newnode->next;
	}
}
