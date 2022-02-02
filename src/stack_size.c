/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:18:57 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/02/01 23:18:57 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_size(t_link *stack)
{
	t_link	*temp;
	int		count;

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
