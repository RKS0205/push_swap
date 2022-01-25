#include "../push_swap.h"
#include <stdio.h>

static void	error_exit(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

static void	check_letters(int argc, char **argv)
{
	int	n;
	int	i;

	if (argc == 1)
		exit(0);
	n = 1;
	while (n < argc)
	{
		i = 0;
		while (argv[n][i] != '\0')
		{
			if (i == 0 && (argv[n][i] == '-' || argv[n][i] == '+'))
				i++;
			if (argv[n][i] < '0' || argv[n][i] > '9')
				error_exit();
			i++;
		}
		n++;
	}
}

static void	check_dups(int argc, char **argv)
{
	int	n;
	int	i;
	int	j;

	n = 1;
	j = 1;
	while (j < argc)
	{
		n = j + 1;
		i = ft_atoi(argv[n - 1]);
		while (n < argc)
		{
			if (i == ft_atoi(argv[n]))
				error_exit();
			n++;
		}
		j++;
	}
}

static void	check_size(int argc, char **argv)
{
	int	n;
	int	i;
	int	j;

	n = 1;
	while (n < argc)
	{
		j = 10;
		i = ft_strlen(argv[n]);
		if (argv[n][0] == '-' || argv[n][0] == '+')
			j = 11;
		if (i > j)
			error_exit();
		if (i == j)
		{
			if (argv[n][0] == '-' && ft_strncmp("-2147483648", argv[n], 11) < 0)
				error_exit();
			if (argv[n][0] == '+')
				argv[n]++;
			if (ft_strncmp("2147483647", argv[n], 10) < 0)
				error_exit();
		}
		n++;
	}
}

void	check_args(int argc, char **argv)
{
	check_letters(argc, argv);
	check_dups(argc, argv);
	check_size(argc, argv);
}
