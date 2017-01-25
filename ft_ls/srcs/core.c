/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 00:41:35 by skyzie            #+#    #+#             */
/*   Updated: 2017/01/24 14:48:11 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ls.h"

void	del(void *content, size_t size)
{
	char	*str;

	str = content;
	ft_strdel(&str);
	size = 0;
}

char	*get_path(char *path, char *str)
{
	char	*slash;
	char	*tmp;

	slash = ft_strjoin(path, "/");
	tmp = ft_strjoin_free(slash, str);
	return (tmp);
}

int		core(char *flags, char *path)
{
	t_list		*lst;
	t_list		*start;

	lst = NULL;
	if (path != NULL)
	{
		lst = open_dir(path, 1, 1);
		print(flags, path, 0);
		ft_putendl("");
	}
	start = lst;
	while (lst != NULL)
	{
		if (ft_strcmp(lst->content, ".") != 0 &&
				ft_strcmp(lst->content, "..") != 0)
			core(flags, get_path(path, lst->content));
		lst = lst->next;
	}
	ft_lstdel(&start, del);
	ft_strdel(&path);
	return (0);
}
