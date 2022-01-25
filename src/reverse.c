/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 03:00:28 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/01/21 03:00:28 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_rra(t_data *data)
{
	write (1, "rra\n", 4);
	if (data->a == NULL)
		return ;
	data->a = data->a->prev;
}

void	do_rrb(t_data *data)
{
	write (1, "rrb\n", 4);
	if (data->b == NULL)
		return ;
	data->b = data->b->prev;
}

void	do_rrr(t_data *data)
{
	write (1, "rrr\n", 4);
	if (data->a != NULL)
		data->a = data->a->prev;
	if (data->b != NULL)
		data->b = data->b->prev;
}
