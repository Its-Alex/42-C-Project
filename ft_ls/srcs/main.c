/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:46:46 by skyzie            #+#    #+#             */
/*   Updated: 2017/01/20 15:32:39 by malexand         ###   ########.fr       */
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

int				main(int argc, char **argv)
{
	char	*flags;
	t_list	*lst;

	if (argc > 1)
	{
		flags = ft_strnew(7);
		if_flags(argv, flags);
		lst = get_dir(flags, argv);
		ft_lstiter(lst, putlst);
		ft_strdel(&flags);
	}
	else
	{
		ft_lstiter(open_dir(".", 0, 1), putlst);
		ft_putchar('\n');
	}
	return (0);
}
