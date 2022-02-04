/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:10:27 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/02/03 20:10:27 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	do_sa(t_data *data)
{
	int	temp;

	if (data->a->next == data->a || data->a == NULL)
		return ;
	temp = data->a->n;
	data->a->n = data->a->next->n;
	data->a->next->n = temp;
}

void	do_sb(t_data *data)
{
	int	temp;

	if (data->b->next == data->b || data->b == NULL)
		return ;
	temp = data->b->n;
	data->b->n = data->b->next->n;
	data->b->next->n = temp;
}

void	do_ss(t_data *data)
{
	int	temp;

	if (data->a->next != data->a && data->a != NULL)
	{
		temp = data->a->n;
		data->a->n = data->a->next->n;
		data->a->next->n = temp;
	}
	if (data->b->next != data->b && data->b != NULL)
	{
		temp = data->b->n;
		data->b->n = data->b->next->n;
		data->b->next->n = temp;
	}
}
