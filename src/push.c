/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 02:58:00 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/01/21 02:58:00 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_stack(t_data *data, char code)
{
	if (code == 'a')
	{
		if (data->a->next == data->a)
			data->a = NULL;
		else
		{
			data->a = data->a->next;
			data->a->prev = data->a->prev->prev;
			data->a->prev->next = data->a;
		}
	}
	else
	{
		if (data->b->next == data->b)
			data->b = NULL;
		else
		{
			data->b = data->b->next;
			data->b->prev = data->b->prev->prev;
			data->b->prev->next = data->b;
		}
	}
}

void	do_pb(t_data *data)
{
	write (1, "pb\n", 3);
	if (data->a == NULL)
		return ;
	data->temp = data->a;
	if (data->b == NULL)
	{
		check_stack(data, 'a');
		data->b = data->temp;
		data->b->next = data->b;
		data->b->prev = data->b;
	}
	else
	{
		check_stack(data, 'a');
		data->temp->next = data->b;
		data->temp->prev = data->b->prev;
		data->b->prev->next = data->temp;
		data->b->prev = data->temp;
		data->b = data->temp;
	}
}

void	do_pa(t_data *data)
{
	write (1, "pa\n", 3);
	if (data->b == NULL)
		return ;
	data->temp = data->b;
	if (data->a == NULL)
	{
		check_stack(data, 'b');
		data->a = data->temp;
		data->a->next = data->a;
		data->a->prev = data->a;
	}
	else
	{
		check_stack(data, 'b');
		data->temp->next = data->a;
		data->temp->prev = data->a->prev;
		data->a->prev->next = data->temp;
		data->a->prev = data->temp;
		data->a = data->temp;
	}
}
