/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:08:37 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/02/03 20:08:37 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
	int		argc;
	char	**argv;
}	t_data;

void	get_args(int argc, char **argv, t_data *data);
void	check_args(int argc, char **argv, t_data *data);
void	make_stack(int argc, char **argv, t_data *data);
char	*get_next_line(int fd);
char	*ft_gnl_strjoin(char *s1, char *s2);
int		str_check(const char *s1, const char *s2);
int		stack_size(t_link *stack);
void	do_pa(t_data *data);
void	do_pb(t_data *data);
void	do_sb(t_data *data);
void	do_sa(t_data *data);
void	do_ss(t_data *data);
void	do_ra(t_data *data);
void	do_rb(t_data *data);
void	do_rr(t_data *data);
void	do_rra(t_data *data);
void	do_rrb(t_data *data);
void	do_rrr(t_data *data);
void	free_stack(t_link *stack);

#endif