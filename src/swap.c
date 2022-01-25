/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 02:57:57 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/01/21 02:57:57 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_sa(t_data *data)
{
	int	temp;

	write (1, "sa\n", 3);
	if (data->a->next == data->a || data->a == NULL)
		return ;
	temp = data->a->num;
	data->a->num = data->a->next->num;
	data->a->next->num = temp;
}

void	do_sb(t_data *data)
{
	int	temp;

	write (1, "sb\n", 3);
	if (data->b->next == data->b || data->b == NULL)
		return ;
	temp = data->b->num;
	data->b->num = data->b->next->num;
	data->b->next->num = temp;
}

void	do_ss(t_data *data)
{
	int	temp;

	write (1, "ss\n", 3);
	if (data->a->next != data->a && data->a != NULL)
	{
		temp = data->a->num;
		data->a->num = data->a->next->num;
		data->a->next->num = temp;
	}
	if (data->b->next != data->b && data->b != NULL)
	{
		temp = data->b->num;
		data->b->num = data->b->next->num;
		data->b->next->num = temp;
	}
}
