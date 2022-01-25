#include "../push_swap.h"

static void	add_to_list(t_link *list, int n)
{
	t_link	*new;
	t_link	*start;

	new = (t_link *) malloc (sizeof(t_link));
	start = list;
	list->prev = new;
	while (list->next != start)
		list = list->next;
	new->prev = list;
	new->n = n;
	new->next = start;
	list->next = new;
}

void	make_stack(int argc, char **argv, t_data *data)
{
	int	n;

	n = 2;
	data->a = (t_link *) malloc (sizeof(t_link));
	data->b = NULL;
	data->a->next = data->a;
	data->a->prev = data->a;
	data->a->n = ft_atoi(argv[1]);
	while (n < argc)
	{
		add_to_list(data->a, ft_atoi(argv[n]));
		n++;
	}
}