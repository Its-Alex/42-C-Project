/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 18:18:44 by malexand          #+#    #+#             */
/*   Updated: 2017/01/20 23:27:32 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ls.h"

static int	is_valid(char *flags, char *path)
{
	t_stat   stats;

	if (stat(path, &stats) == -1)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(path);
		ft_putendl(": No such file or directory");
		return (1);
	}
	else
	{
		if (S_ISDIR(stats.st_mode) == 0)
		{
			ft_putstr("Is not dir : ");
			ft_putendl(path);
			//print_file(flags, path);
			return (1);
		}
  	}
  	(void)flags;
  	return (0);
}

static t_list		*getlst(char **argv)
{
	int		count;
	t_list	*args;
	t_list	*tmp;

	count = 1;
	args = NULL;
	while (argv[count])
		if (argv[count][0] == '-')
			count++;
		else
			break ;
	while (argv[count] != NULL)
	{
		if (args == NULL)
			args = ft_lstnew(argv[count], sizeof(char) *
				(ft_strlen(argv[count]) + 1));
		else
		{
			tmp = ft_lstnew(argv[count], sizeof(char) *
				(ft_strlen(argv[count]) + 1));
			ft_lstadd(&args, tmp);
		}
		count++;
	}
	return (args);
}

t_list 			*getdir(char *flags, char **argv)
{
	t_list	*lst;
	t_list	*start;
	t_list	*prev;
	t_list	*tmp;

	lst = getlst(argv);
	lst = ft_lststr_sort(lst);
	start = lst;
	prev = NULL;
	tmp = NULL;
	while (lst)
	{
		if (is_valid(flags, lst->content) == 1)
		{
			tmp = lst;
			lst = lst->next;
			if (prev == NULL)
				start = lst;
			else
				prev->next = lst;
			ft_lstdelone(&tmp, del);

		}
		else
		{
			prev = lst;
			lst = lst->next;
		}
	}
	ft_lstiter(start, putlst);
	return (start);
}