/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:10:46 by jvelasco          #+#    #+#             */
/*   Updated: 2022/11/16 17:25:09 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_queue(t_queue *q)
{
	q->head = NULL;
	q->tail = NULL;
}

t_checker	reset_checkers(t_checker *checker)
{
	checker->small_num = 0;
	checker->number = -1;
	checker->last_number = 0;
	return (*checker);
}

void	free_list(t_queue *q, t_queue *q2)
{
	while (q2->head != NULL)
	{
		ft_printf("pa\n");
		push_node(q2, q);
	}
}

int	enqueue(t_queue *q, int value, int real_val)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (newnode == NULL)
		return (0);
	newnode->value = value;
	newnode->real_val = real_val;
	newnode->next = NULL;
	if (q->tail != NULL)
	{
		newnode->prev = q->tail;
		q->tail->next = newnode;
	}
	else
		newnode->prev = NULL;
	q->tail = newnode;
	if (q->head == NULL)
		q->head = newnode;
	return (0);
}

int	dequeue(t_queue *q)
{
	int		result;
	t_node	*tmp;

	if (q->head == NULL)
		return (0);
	tmp = q->head;
	result = tmp->value;
	q->head = q->head->next;
	if (q->head == NULL)
		q->tail = NULL;
	free(tmp);
	return (result);
}
