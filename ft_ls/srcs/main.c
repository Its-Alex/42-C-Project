/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:46:46 by skyzie            #+#    #+#             */
/*   Updated: 2017/01/24 15:13:17 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void			putlst(t_list *lst)
{
	ft_putstr(lst->content);
	if (lst->next)
		ft_putchar(' ');
}

static void	put_err(char **argv)
{
	t_stat	stats;
	int		count;

	count = 1;
	while (argv[count])
		if (argv[count][0] == '-')
			count++;
		else
			break ;
	while (argv[count])
	{
		if (stat(argv[count], &stats) == -1)
		{
			ft_putstr("ft_ls: ");
			ft_putstr(get_filename(argv[count]));
			ft_putstr(": No such file or directory\n");
		}
		count++;
	}
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
		put_err(argv);
		lst = getdir(flags, argv);
		if (lst != NULL)
		{
			ft_putendl("");
			while (lst)
			{
				core(flags, lst->content);
				if (lst->next)
					lst = lst->next;
				else
					break ;
			}
		}
		ft_strdel(&flags);
	}
	else
	{
		ft_lstiter(open_dir(".", 0, 1), putlst);
		ft_putchar('\n');
	}
	return (0);
}
