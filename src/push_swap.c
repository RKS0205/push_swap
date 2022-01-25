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
			printf ("%i %i\n", data->a->num, data->a->check);
			data->a = data->a->next;
		}
		printf ("%i %i\n", data->a->num, data->a->check);
		data->a = data->temp;
	}
	if (data->b != NULL)
	{
		write (1, "b\n", 2);
		data->temp = data->b;
		while (data->b->next != data->temp)
		{
			printf ("%i %i\n", data->b->num, data->b->check);
			data->b = data->b->next;
		}
		printf ("%i %i\n", data->b->num, data->b->check);
		data->b = data->temp;
	}
}

int	get_max_nbr(t_link *stack, t_data *data)
{
	int	max;

	max = stack->num;
	data->temp = stack;
	while (stack->next != data->temp)
	{
		if (stack->num > max)
			max = stack->num;
		stack = stack->next;
	}
	if (stack->num > max)
		max = stack->num;
	stack = data->temp;
	return (max);
}

int	get_min_nbr(t_link *stack, t_data *data)
{
	int	min;

	min = stack->num;
	data->temp = stack;
	while (stack->next != data->temp)
	{
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	if (stack->num < min)
		min = stack->num;
	stack = data->temp;
	return (min);
}

int	count_stack(t_link *stack)
{
	int		count;
	int		n;
	t_link	*temp;

	temp = stack;
	count = 1;
	n = stack->num;
	stack = stack->next;
	while (stack != temp)
	{
		if (stack->num > n)
		{
			count++;
			n = stack->num;
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
	data->a = data->a->next;
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
	n = data->a->num;
	data->a = data->a->next;
	while (data->a != data->temp)
	{
		if (data->a->num > n)
		{
			data->a->check = 1;
			n = data->a->num;
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
	temp = data->a->num;
	data->a->num = data->a->next->num;
	data->a->next->num = temp;
	if (get_best_count(data) > data->count)
	{
		temp = data->a->num;
		data->a->num = data->a->next->num;
		data->a->next->num = temp;
		return (1);
	}
	temp = data->a->num;
	data->a->num = data->a->next->num;
	data->a->next->num = temp;
	return (0);
}

int	check_stack(t_data *data)
{
	data->temp = data->a;
	while (data->a->next != data->temp)
	{
		if (data->a->check == 0)
			return (0);
		data->a = data->a->next;
	}
	if (data->a->check == 0)
		return (0);
	data->a = data->temp;
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	check_args(argc, argv);
	data = (t_data *) malloc (sizeof(t_data));
	make_stack(argc, argv, data);
	test_stack(data);
	if (argc < 3)
		exit (0);
	if (argc == 3)
	{
		if (data->a->num > data->a->next->num)
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
	}
	test_stack(data);
}
