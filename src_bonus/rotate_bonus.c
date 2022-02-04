/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:10:14 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/02/03 20:10:14 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	do_ra(t_data *data)
{
	if (data->a == NULL)
		return ;
	data->a = data->a->next;
}

void	do_rb(t_data *data)
{
	if (data->b == NULL)
		return ;
	data->b = data->b->next;
}

void	do_rr(t_data *data)
{
	if (data->a != NULL)
		data->a = data->a->next;
	if (data->b != NULL)
		data->b = data->b->next;
}
