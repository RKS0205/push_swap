/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:19:00 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/02/01 23:19:00 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	test_sa(t_data *data)
{
	int	temp;

	data->count = get_best_check(data);
	temp = data->a->n;
	data->a->n = data->a->next->n;
	data->a->next->n = temp;
	if (get_best_check(data) > data->count)
	{
		temp = data->a->n;
		data->a->n = data->a->next->n;
		data->a->next->n = temp;
		return (1);
	}
	temp = data->a->n;
	data->a->n = data->a->next->n;
	data->a->next->n = temp;
	return (0);
}
