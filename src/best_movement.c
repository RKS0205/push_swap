/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:18:19 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/02/01 23:18:19 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_moves_a(t_data *data)
{
	t_link	*temp;
	int		count;

	temp = data->a;
	count = 0;
	while (data->a->next != temp)
	{
		if ((data->b->n < data->a->n && data->b->n > data->a->prev->n)
			|| (data->b->n < get_min_nbr(data->a)
				&& data->a->n == get_min_nbr(data->a)))
		{
			data->a = temp;
			if (count > stack_size(data->a) / 2)
				return (count - stack_size(data->a));
			return (count);
		}
		count++;
		data->a = data->a->next;
	}
	data->a = temp;
	if (count > stack_size(data->a) / 2)
		return (count - stack_size(data->a));
	return (count);
}

static int	count_moves_b(t_data *data)
{
	t_link	*temp;
	int		count;

	count = 0;
	temp = data->temp;
	while (temp != data->b)
	{
		temp = temp->next;
		count++;
	}
	if (count > stack_size(data->b) / 2)
		return (count - stack_size(data->b));
	return (count);
}

static int	get_ideal_count(t_data *data)
{
	int	count;

	if ((data->move_a >= 0 && data->move_b >= 0)
		|| (data->move_a < 0 && data->move_b < 0))
	{
		if (data->move_a >= data->move_b && data->move_a >= 0)
			count = data->move_a;
		else if (data->move_b >= data->move_a && data->move_b >= 0)
			count = data->move_b;
		else if (data->move_a <= data->move_b && data->move_a < 0)
			count = data->move_a * -1;
		else
			count = data->move_b * -1;
	}
	else
	{
		count = data->move_a - data->move_b;
		if (count < 0)
			count *= -1;
	}
	return (count);
}

void	best_movement(t_data *data)
{
	int		count;
	t_link	*temp;

	data->temp = data->b;
	data->move_b = count_moves_b(data);
	data->move_a = count_moves_a(data);
	count = get_ideal_count(data);
	temp = data->b;
	data->b = data->b->next;
	while (data->b != data->temp)
	{
		data->move_b = count_moves_b(data);
		data->move_a = count_moves_a(data);
		if (count > get_ideal_count(data))
		{
			count = get_ideal_count(data);
			temp = data->b;
		}
		data->b = data->b->next;
	}
	while (data->b != temp)
		data->b = data->b->next;
	data->move_b = count_moves_b(data);
	data->move_a = count_moves_a(data);
	data->b = data->temp;
}
