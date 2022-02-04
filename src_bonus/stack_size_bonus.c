/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:10:18 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/02/03 20:10:18 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	stack_size(t_link *stack)
{
	t_link	*temp;
	int		count;

	if (stack == NULL)
		return (0);
	temp = stack;
	count = 1;
	while (stack->next != temp)
	{
		stack = stack->next;
		count++;
	}
	stack = temp;
	return (count);
}
