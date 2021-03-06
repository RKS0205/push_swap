/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:18:32 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/02/01 23:18:32 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max_nbr(t_link *stack)
{
	int		max;
	t_link	*temp;

	max = stack->n;
	temp = stack;
	while (stack->next != temp)
	{
		if (stack->n > max)
			max = stack->n;
		stack = stack->next;
	}
	if (stack->n > max)
		max = stack->n;
	stack = temp;
	return (max);
}

int	get_min_nbr(t_link *stack)
{
	int		min;
	t_link	*temp;

	min = stack->n;
	temp = stack;
	while (stack->next != temp)
	{
		if (stack->n < min)
			min = stack->n;
		stack = stack->next;
	}
	if (stack->n < min)
		min = stack->n;
	stack = temp;
	return (min);
}
