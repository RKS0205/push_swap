#include "../push_swap.h"

void	get_order(t_data *data)
{
	int	min;
	int	cmp;
	int	order;

	min = get_min_nbr(data->a);
	data->temp = data->a;
	order = 0;
	while (data->a->n != min)
		data->a = data->a->next;
	data->a->order = order++;
	cmp = min;
	while (cmp != get_max_nbr(data->a))
	{
		if (data->a->n == min && min > cmp)
		{
			data->a->order = order++;
			cmp = min;
		}
		if (data->a->n > cmp && (data->a->n < min || min == cmp))
			min = data->a->n;
		data->a = data->a->next;
	}
	data->a = data->temp;
}
