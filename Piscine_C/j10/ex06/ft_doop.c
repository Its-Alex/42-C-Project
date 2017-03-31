/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 21:03:01 by malexand          #+#    #+#             */
/*   Updated: 2015/07/22 21:03:04 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/includes/fonction_solver.h"

int		ft_check(char **argv)
{
	int		i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] < '0' || argv[0][i] > '9')
			return (0);
		i++;
	}
	i = 0;
	while (argv[3][i] != '\0')
	{
		if (argv[3][i] < '0' || argv[3][i] > '9')
			return (0);
		i++;
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		if (argv[2][i] != 42 || argv[2][i] != 37 || argv[2][i] != 47
				|| argv[2][i] != 43 || argv[2][i] != 45)
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		k;

	i = 0;
	if (argc == 4 && ft_check(argv))
	{
	}
	else
		ft_putchar(0);
	return (0);
}
