/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 03:00:30 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/01/21 03:00:30 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_ra(t_data *data)
{
	write (1, "ra\n", 3);
	if (data->a == NULL)
		return ;
	data->a = data->a->next;
}

void	do_rb(t_data *data)
{
	write (1, "rb\n", 3);
	if (data->b == NULL)
		return ;
	data->b = data->b->next;
}

void	do_rr(t_data *data)
{
	write (1, "rr\n", 3);
	if (data->a != NULL)
		data->a = data->a->next;
	if (data->b != NULL)
		data->b = data->b->next;
}
