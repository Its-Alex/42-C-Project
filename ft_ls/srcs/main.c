/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:46:46 by skyzie            #+#    #+#             */
/*   Updated: 2017/01/13 23:02:05 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int		ifFlags(char **av, char *flags)
{
	int		line;
	int		column;
	int		count;

	count = 0;
	line = 1;
	while (av[line])
	{
		column = 0;
		if (av[line][0] == '-')
		{
			while (av[line][column++])
				if (av[line][column] == 'l' || av[line][column] == 'r' ||
					av[line][column] == 't' || av[line][column] == 'R' ||
					av[line][column] == 'a')
					if(ft_strchr(flags, av[line][column]) == NULL)
						flags[count++] = av[line][column];
		}
		else
			break;
		line++;
	}
	return (0);
}

int 			main(int argc, char **argv)
{
	char	*flags;

	(void)argc;
	flags = ft_strnew(5);
	ifFlags(argv, flags);
	read_dir(argv[1]);
	ft_strdel(&flags);
	return (0);
}