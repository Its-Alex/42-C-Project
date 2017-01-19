/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:46:46 by skyzie            #+#    #+#             */
/*   Updated: 2017/01/19 18:23:43 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void			putlst(t_list *lst)
{
	ft_putstr(lst->content);
	if (lst->next)
		ft_putchar(' ');
}

static int		if_flags(char **av, char *flags)
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
					av[line][column] == 'a' || av[line][column] == 's' ||
					av[line][column] == 'f')
					if (ft_strchr(flags, av[line][column]) == NULL)
						flags[count++] = av[line][column];
		}
		else
			break ;
		line++;
	}
	return (0);
}

static void		sort(char *flags, char **argv)
{
	// int		count;
	char	*path;

	// count = 1;
	// path == NULL;
	// while (argv[count])
	// {
	// 	while (argv[count][0] == '-')
	// 		count++;
	// 	if (path == NULL)
	// 	{
	// 		path = ft_strnew(ft_strlen(argv[1]));
	// 		path = ft_strcpy(path, argv[1]);
	// 	}
	// 	else
	// 	{

	// 	}
	// }
	path = ft_strnew(ft_strlen(argv[1]));
	path = ft_strcpy(path, argv[1]);
	core(flags, path);
}

int				main(int argc, char **argv)
{
	char	*flags;

	if (argc > 1)
	{
		flags = ft_strnew(7);
		if_flags(argv, flags);
		sort(flags, argv);
		ft_strdel(&flags);
	}
	else
	{
		ft_lstiter(open_dir(".", 0, 1), putlst);
		ft_putchar('\n');
	}
	return (0);
}
