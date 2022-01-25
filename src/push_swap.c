#include "../push_swap.h"
#include <stdio.h>

void	test_stack(t_data *data)
{
	if (data->a != NULL)
	{
		write (1, "a\n", 2);
		data->temp = data->a;
		while (data->a->next != data->temp)
		{
			printf ("%i %i\n", data->a->n, data->a->check);
			data->a = data->a->next;
		}
		printf ("%i %i\n", data->a->n, data->a->check);
		data->a = data->temp;
	}
	if (data->b != NULL)
	{
		write (1, "b\n", 2);
		data->temp = data->b;
		while (data->b->next != data->temp)
		{
			printf ("%i %i\n", data->b->n, data->b->check);
			data->b = data->b->next;
		}
		printf ("%i %i\n", data->b->n, data->b->check);
		data->b = data->temp;
	}
}

int	get_max_nbr(t_link *stack, t_data *data)
{
	int	max;

	max = stack->n;
	data->temp = stack;
	while (stack->next != data->temp)
	{
		if (stack->n > max)
			max = stack->n;
		stack = stack->next;
	}
	if (stack->n > max)
		max = stack->n;
	stack = data->temp;
	return (max);
}

int	get_min_nbr(t_link *stack)
{
	int	min;
	t_link	*temp;

	min = stack->n;
	temp = stack;
	while (stack->next != temp)
	{
		if (stack->n < min)
			min = stack->n;
		stack = stack->next;
	}
	if (stack->n < min)
		min = stack->n;
	stack = temp;
	return (min);
}

int	count_stack(t_link *stack)
{
	int		count;
	int		n;
	t_link	*temp;

	temp = stack;
	count = 1;
	n = stack->n;
	stack = stack->next;
	while (stack != temp)
	{
		if (stack->n > n)
		{
			count++;
			n = stack->n;
		}
		stack = stack->next;
	}
	return (count);
}

int	get_best_count(t_data *data)
{
	int		count;

	data->temp = data->a;
	count = 0;
	while (data->a->next != data->temp)
	{
		if (count_stack(data->a) > count)
			count = count_stack(data->a);
		data->a = data->a->next;
	}
	if (count_stack(data->a) > count)
			count = count_stack(data->a);
	data->a = data->temp;
	return (count);
}

void	update_stack_check(t_data *data)
{
	t_link	*temp;
	int		n;

	temp = data->a;
	while (count_stack(data->a) != get_best_count(data))
		data->a = data->a->next;
	data->temp = data->a;
	data->a->check = 1;
	n = data->a->n;
	data->a = data->a->next;
	while (data->a != data->temp)
	{
		if (data->a->n > n)
		{
			data->a->check = 1;
			n = data->a->n;
		}
		else
			data->a->check = 0;
		data->a = data->a->next;
	}
	data->a = temp;
}

int	test_sa(t_data *data)
{
	int	temp;

	data->count = get_best_count(data);
	temp = data->a->n;
	data->a->n = data->a->next->n;
	data->a->next->n = temp;
	if (get_best_count(data) > data->count)
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

int	check_stack(t_data *data)
{
	int	n;

	data->temp = data->a;
	n = 1;
	while (data->a->next != data->temp)
	{
		if (data->a->check == 0)
			n = 0;
		data->a = data->a->next;
	}
	if (data->a->check == 0)
		n = 0;
	data->a = data->temp;
	return (n);
}

int	count_moves_a(t_data *data)
{
	t_link	*temp;
	int		count;

	temp = data->a;
	count = 0;
	while (data->a->next != temp)
	{
		if ((data->b->n < data->a->n && data->b->n > data->a->prev->n)
			|| (data->b->n < get_min_nbr(data->a)
				&& data->a->n == get_min_nbr(data->a)))
		{
			data->a = temp;
			if (count > (data->argc - 1) / 2)
				return (count - (data->argc - 1));
			return (count);
		}
		count++;
		data->a = data->a->next;
	}
	data->a = temp;
	if (count > (data->argc - 1) / 2)
		return (count - (data->argc - 1));
	return (count);
}

int	count_moves_b(t_data *data)
{
	t_link	*temp;
	int		count;

	count = 0;
	temp = data->temp;
	while (temp != data->b)
	{
		temp = temp->next;
		count++;
	}
	if (count > (data->argc - 1) / 2)
		return (count - (data->argc - 1));
	return (count);
}

int	get_ideal_count(t_data *data)
{
	int	count;

	if ((data->move_a >= 0 && data->move_b >= 0)
		|| (data->move_a < 0 && data->move_b < 0))
	{
		if (data->move_a > data->move_b && data->move_a >= 0)
			count = data->move_a;
		else if (data->move_b > data->move_a && data->move_b >= 0)
			count = data->move_b;
		else if (data->move_a < data->move_b && data->move_a < 0)
			count = data->move_a * -1;
		else
			count = data->move_b * -1;
	}
	else
	{
		count = data->move_a - data->move_b;
		if (count < 0)
			count *= -1;
		if (count > data->move_a + data->argc - 1 && data->move_a < 0)
			count = data->move_a + data->argc - 1;
		if (count > data->move_b + data->argc - 1 && data->move_b < 0)
			count = data->move_b + data->argc - 1;
	}
	return (count);
}

void	best_movement(t_data *data)
{
	int		count;
	t_link	*temp;

	data->temp = data->b;
	count = 0;
	data->move_b = count_moves_b(data);
	data->move_a = count_moves_a(data);
	if (count > get_ideal_count(data) || count == 0)
	{
		count = get_ideal_count(data);
		temp = data->b;
	}
	data->b = data->b->next;
	while (data->b != data->temp)
	{
		data->move_b = count_moves_b(data);
		data->move_a = count_moves_a(data);
		if (count > get_ideal_count(data))
		{
			count = get_ideal_count(data);
			temp = data->b;
		}
		data->b = data->b->next;
	}
	while (data->b != temp)
		data->b = data->b->next;
	data->move_b = count_moves_b(data);
	data->move_a = count_moves_a(data);
	if (count > data->move_a + data->argc - 1 && data->move_a < 0)
		data->move_a += data->argc - 1;
	if (count > data->move_b + data->argc - 1 && data->move_b < 0)
		data->move_b += data->argc - 1;
}

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

int	main(int argc, char **argv)
{
	t_data	*data;

	check_args(argc, argv);
	data = (t_data *) malloc (sizeof(t_data));
	data->argc = argc;
	make_stack(argc, argv, data);
	if (argc < 3)
		exit (0);
	if (argc == 3)
	{
		if (data->a->n > data->a->next->n)
			do_ra(data);
	}
	else
	{
		update_stack_check(data);
		while (!check_stack(data))
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
		test_stack(data);
		while (data->b != NULL)
		{
			best_movement(data);
			while (data->move_b != 0 || data->move_a != 0)
				smart_rotate(data);
			do_pa(data);
		}
		while (data->a->n != get_min_nbr(data->a))
		{
			data->temp = data->a;
			data->count = 0;
			while (data->a->n != get_min_nbr(data->a))
			{
				data->a = data->a->next;
				data->count++;
			}
			if (data->count > (data->argc - 1) / 2)
				data->count -= data->argc - 1;
			data->move_a = data->count;
			data->a = data->temp;
			while (data->move_a != 0)
				smart_rotate(data);
		}
	}
	test_stack(data);
}
