/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:18:54 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/02/01 23:18:54 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_for_false(t_data *data)
{
	int	n;

	data->temp = data->a;
	n = 1;
	while (data->a->next != data->temp)
	{
		if (data->a->check == 0)
			n = 0;
		data->a = data->a->next;
	}
	if (data->a->check == 0)
		n = 0;
	data->a = data->temp;
	return (n);
}

int	check_stack(t_link *stack)
{
	int		count;
	int		n;
	t_link	*temp;

	temp = stack;
	count = 1;
	n = stack->n;
	stack = stack->next;
	while (stack != temp)
	{
		if (stack->n > n)
		{
			count++;
			n = stack->n;
		}
		stack = stack->next;
	}
	return (count);
}

int	get_best_check(t_data *data)
{
	int		count;

	data->temp = data->a;
	count = 0;
	while (data->a->next != data->temp)
	{
		if (check_stack(data->a) > count)
			count = check_stack(data->a);
		data->a = data->a->next;
	}
	if (check_stack(data->a) > count)
			count = check_stack(data->a);
	data->a = data->temp;
	return (count);
}

void	update_stack_check(t_data *data)
{
	t_link	*temp;
	int		n;

	temp = data->a;
	while (check_stack(data->a) != get_best_check(data))
		data->a = data->a->next;
	data->temp = data->a;
	data->a->check = 1;
	n = data->a->n;
	data->a = data->a->next;
	while (data->a != data->temp)
	{
		if (data->a->n > n)
		{
			data->a->check = 1;
			n = data->a->n;
		}
		else
			data->a->check = 0;
		data->a = data->a->next;
	}
	data->a = temp;
}
