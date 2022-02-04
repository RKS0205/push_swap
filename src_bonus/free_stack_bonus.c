/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:09:41 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/02/03 20:09:41 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	free_stack(t_link *stack)
{
	int	size;

	size = stack_size(stack);
	if (size == 0)
		return ;
	if (size == 2)
	{
		free (stack->prev);
		free (stack);
		return ;
	}
	if (size == 1)
	{
		free (stack);
		return ;
	}
	stack = stack->next;
	while (size > 2)
	{
		free (stack->prev);
		stack = stack->next;
		size--;
	}
	free (stack->prev);
	free (stack);
}
