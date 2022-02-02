/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:18:50 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/02/01 23:18:50 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	smart_rotate(t_data *data)
{
	if (data->move_b < 0 && data->move_a < 0
		&& data->move_b++ && data->move_a++)
		do_rrr(data);
	else if (data->move_b > 0 && data->move_a > 0
		&& data->move_b-- && data->move_a--)
		do_rr(data);
	else if (data->move_b > 0 && data->move_b--)
		do_rb(data);
	else if (data->move_a > 0 && data->move_a--)
		do_ra(data);
	else if (data->move_b < 0 && data->move_b++)
		do_rrb(data);
	else if (data->move_a < 0 && data->move_a++)
		do_rra(data);
}
