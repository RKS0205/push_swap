/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 02:57:28 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/01/21 02:57:28 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_link
{
	int				check;
	int				n;
	struct s_link	*next;
	struct s_link	*prev;
}	t_link;

typedef struct s_data
{
	t_link	*a;
	t_link	*b;
	t_link	*temp;
	int		count;
	int		move_a;
	int		move_b;
	int		argc;
	char	**argv;
}	t_data;

void	check_args(int argc, char **argv, t_data *data);
void	do_pb(t_data *data);
void	make_stack(int argc, char **argv, t_data *data);
void	do_pa(t_data *data);
void	do_sb(t_data *data);
void	do_sa(t_data *data);
void	do_ss(t_data *data);
void	do_ra(t_data *data);
void	do_rb(t_data *data);
void	do_rr(t_data *data);
void	do_rra(t_data *data);
void	do_rrb(t_data *data);
void	do_rrr(t_data *data);
int		get_min_nbr(t_link *stack);
int		get_max_nbr(t_link *stack);
void	get_order(t_data *data);
void	best_movement(t_data *data);
int		stack_size(t_link *stack);
int		check_for_false(t_data *data);
int		check_stack(t_link *stack);
int		get_best_check(t_data *data);
void	update_stack_check(t_data *data);
int		test_sa(t_data *data);
void	smart_rotate(t_data *data);
void	free_stack(t_link *stack);
void	get_args(int argc, char **argv, t_data *data);

#endif