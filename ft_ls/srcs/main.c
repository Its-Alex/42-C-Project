/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:46:46 by skyzie            #+#    #+#             */
/*   Updated: 2017/01/17 00:57:15 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void			putlst(t_list *lst)
{
	ft_putstr(lst->content);
	if (lst->next)
		ft_putstr(" ");
}

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
					av[line][column] == 'a' || av[line][column] == 's')
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

	if (argc > 1)
	{
		flags = ft_strnew(6);
		ifFlags(argv, flags);
		core(flags, argv);
		ft_strdel(&flags);
	}
	else
		ft_lstiter(ft_lststr_sort(open_dir(".", 0)), putlst);
	return (0);
}