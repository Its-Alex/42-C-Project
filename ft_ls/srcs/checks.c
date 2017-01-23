/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 18:18:44 by malexand          #+#    #+#             */
/*   Updated: 2017/01/23 17:03:06 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ls.h"

static int	is_valid(char *flags, char *path)
{
	t_stat	stats;
	char	*tmp;

	tmp = NULL;
	if (stat(path, &stats) == -1)
	{
		tmp = ft_strnew(0);
		tmp = ft_strjoin_free(tmp, "ft_ls: ");
		tmp = ft_strjoin_free(tmp, get_filename(path));
		tmp = ft_strjoin_free(tmp, ": No such file or directory\n");
		ft_putstr(tmp);
		return (-1);
	}
	else
	{
		if (S_ISDIR(stats.st_mode) == 0)
		{
			print(flags, path);
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
			ft_lstadd(&args, ft_lstnew(argv[count], sizeof(char) *
				(ft_strlen(argv[count]) + 1)));
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
	int		val;

	lst = getlst(argv);
	lst = ft_lststr_sort(lst);
	start = lst;
	prev = NULL;
	tmp = NULL;
	while (lst)
	{
		val = is_valid(flags, lst->content);
		if (val == 1 || val == -1)
		{
			tmp = lst;
			lst = lst->next;
			if (prev == NULL)
				start = lst;
			else
				prev->next = lst;
			ft_lstdelone(&tmp, del);
			if (val == 1 && ft_strchr(flags, 'l') == NULL && lst != NULL)
				if (lst->next != NULL || ft_strcmp(lst->content,
						start->content) == 0)
					ft_putchar(' ');
		}
		else
		{
			prev = lst;
			lst = lst->next;
		}
	}
	if (start != NULL)
		if (ft_strlen(start->content) > 0)
			ft_putendl("");
	return (start);
}