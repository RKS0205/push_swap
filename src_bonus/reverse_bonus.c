/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:10:10 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/02/03 20:10:10 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	do_rra(t_data *data)
{
	if (data->a == NULL)
		return ;
	data->a = data->a->prev;
}

void	do_rrb(t_data *data)
{
	if (data->b == NULL)
		return ;
	data->b = data->b->prev;
}

void	do_rrr(t_data *data)
{
	if (data->a != NULL)
		data->a = data->a->prev;
	if (data->b != NULL)
		data->b = data->b->prev;
}
