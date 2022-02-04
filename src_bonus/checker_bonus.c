/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:09:00 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/02/03 20:09:00 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	instruction_error(char *line, t_data *data)
{
	write (2, "Error\n", 6);
	free (line);
	free_stack(data->a);
	free_stack(data->b);
	free_split(data->argv);
	free (data);
	exit (1);
}

void	execute_instruction(char *line, t_data *data)
{
	if (str_check(line, "sa\n"))
		do_sa(data);
	else if (str_check(line, "sb\n"))
		do_sb(data);
	else if (str_check(line, "ss\n"))
		do_ss(data);
	else if (str_check(line, "pa\n"))
		do_pa(data);
	else if (str_check(line, "pb\n"))
		do_pb(data);
	else if (str_check(line, "ra\n"))
		do_ra(data);
	else if (str_check(line, "rb\n"))
		do_rb(data);
	else if (str_check(line, "rr\n"))
		do_rr(data);
	else if (str_check(line, "rra\n"))
		do_rra(data);
	else if (str_check(line, "rrb\n"))
		do_rrb(data);
	else if (str_check(line, "rrr\n"))
		do_rrr(data);
	else
		instruction_error(line, data);
}

void	gnl_loop(t_data *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			return ;
		else
		{
			execute_instruction(line, data);
			free (line);
		}
	}
}

void	check_if_correct(t_data *data)
{
	if (data->b != NULL)
	{
		write (1, "KO\n", 3);
		return ;
	}
	data->temp = data->a;
	while (data->a->next != data->temp)
	{
		if (data->a->n > data->a->next->n)
		{
			write (1, "KO\n", 3);
			data->a = data->temp;
			return ;
		}
		data->a = data->a->next;
	}
	write (1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *) malloc (sizeof(t_data));
	get_args(argc, argv, data);
	check_args(data->argc, data->argv, data);
	make_stack(data->argc, data->argv, data);
	gnl_loop(data);
	check_if_correct(data);
	free_stack(data->a);
	free_split(data->argv);
	free (data);
}
