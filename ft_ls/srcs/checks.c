/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 18:18:44 by malexand          #+#    #+#             */
/*   Updated: 2017/01/20 16:06:01 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ls.h"

static int	is_valid(char *flags, char *path)
{
	t_stat   buffer;

	if (stat(path, &buffer) == 0)
	{
		ft_putstr_color("Error", RED);
		ft_putstr(" : ");
		ft_putstr("ft_ls: ");
		ft_putstr(path);
		ft_putendl(": No such file or directory");
		return (1);
	}
	else
	{
		if (S_ISDIR(buffer.st_mode) == 0)
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

static t_list		*sort(char **argv)
{
	int		count;
	t_list	*args;
	t_list	*tmp;
	t_list	*start;

	count = 1;
	args = NULL;
	while (argv[count])
	{
		ft_putendl(argv[count]);
		while (argv[count][0] == '-')
			count++;
		if (args == NULL)
		{
				args = ft_lstnew(argv[count], sizeof(char) *
					(ft_strlen(argv[count]) + 1));
				start = args;
		}
		else
		{
			tmp = ft_lstnew(argv[count], sizeof(char) *
				(ft_strlen(argv[count]) + 1));
			ft_lstadd(&args, tmp);
		}
		count++;
	}
	start = ft_lststr_sort(start);
	ft_lstiter(start, putlst);
	return (start);
}

t_list 			*get_dir(char *flags, char **argv)
{
	t_list	*lst;
	t_list	*start;
	t_list	*prev;
	t_list	*tmp;

	lst = sort(argv);
	start = lst;
	ft_putendl("START");
	prev = NULL;
	tmp = NULL;
	while (lst)
	{
		if (is_valid(flags, lst->content) == 1)
		{
			if (prev == NULL)
			{
				tmp = lst;
				lst = lst->next;
				start = lst;
				ft_lstdelone(&tmp, del);
			}
			else
			{
				tmp = lst;
				lst = lst->next;
				prev->next = lst;
				ft_lstdelone(&tmp, del);
			}

		}
		prev = lst;
		lst = lst->next;
	}
	return (start);
}