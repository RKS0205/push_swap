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
}	t_data;

void	check_args(int argc, char **argv);
void	do_pb(t_data *data);
void	make_stack(int argc, char **argv, t_data *data);
void	test_stack(t_data *data);
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

#endif