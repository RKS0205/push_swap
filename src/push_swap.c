/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:18:44 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/02/01 23:18:44 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb_loop(t_data *data)
{
	update_stack_check(data);
	while (!check_for_false(data))
	{
		if (test_sa(data) != 0)
		{
			do_sa(data);
			update_stack_check(data);
		}
		else if (data->a->check == 0)
			do_pb(data);
		else
			do_ra(data);
	}
}

void	pa_loop(t_data *data)
{
	data->move_a = 0;
	data->move_b = 0;
	while (data->b != NULL)
	{
		best_movement(data);
		while (data->move_b != 0 || data->move_a != 0)
			smart_rotate(data);
		do_pa(data);
	}
}

void	rotate_loop(t_data *data)
{
	data->temp = data->a;
	data->count = 0;
	while (data->a->n != get_min_nbr(data->a))
	{
		data->a = data->a->next;
		data->count++;
	}
	if (data->count > stack_size(data->a) / 2)
		data->count -= stack_size(data->a);
	data->move_a = data->count;
	data->a = data->temp;
	while (data->move_a != 0)
		smart_rotate(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *) malloc (sizeof(t_data));
	get_args(argc, argv, data);
	check_args(data->argc, data->argv, data);
	make_stack(data->argc, data->argv, data);
	pb_loop(data);
	pa_loop(data);
	rotate_loop(data);
	free_stack(data->a);
	free_split(data->argv);
	free (data);
}
