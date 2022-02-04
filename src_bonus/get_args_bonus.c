/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:09:47 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/02/03 20:09:47 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	get_args(int argc, char **argv, t_data *data)
{
	int		i;
	int		size;
	char	*line;

	if (argc == 1)
		exit (0);
	i = 0;
	size = 0;
	while (i < argc)
		size += ft_strlen(argv[i++]) + 1;
	line = calloc (sizeof(char), size);
	ft_strlcat(line, argv[0], ft_strlen(argv[0]) + 2);
	i = 1;
	while (i < argc)
	{
		ft_strlcat(line, " ", ft_strlen(line) + 2);
		ft_strlcat(line, argv[i], ft_strlen(line) + ft_strlen(argv[i]) + 2);
		i++;
	}
	data->argv = ft_split(line, ' ');
	free (line);
	data->argc = 0;
	while (data->argv[data->argc] != NULL)
		data->argc++;
}
