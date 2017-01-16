/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 22:42:09 by skyzie            #+#    #+#             */
/*   Updated: 2017/01/16 15:21:58 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	putlst(t_list *lst)
{
	ft_putendl(lst->content);
}

t_list		*ft_lstsort(t_list *list)
{
	return (list);
}

int		open_dir(char *path, int sneaky)
{
	DIR				*dir;
	t_dir			*ent;
	t_list			*list;
	t_list			*tmp;

	list = NULL;
	tmp = NULL;
	if ((dir = opendir(path)) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			if (ent->d_name[0] != '.' || sneaky == 1)
			{
				if (list == NULL)
					list = ft_lstnew(ent->d_name, sizeof(char) * (ft_strlen(ent->d_name) + 1));
				else
				{
					tmp = ft_lstnew(ent->d_name, sizeof(char) * (ft_strlen(ent->d_name) + 1));
					ft_lstadd(&list, tmp);
				}
			}
		}
		closedir(dir);
	}
	else
	{
		ft_putendl(path);
		return (1);
	}
	list = ft_lstsort(list);
	ft_lstiter(list, putlst);
	return (0);
}

int		read_dir(char *path)
{
	DIR		*dir;
	t_dir	*ent;

	if (path == NULL)
		path = ".";
	if ((dir = opendir(path)))
	{
		while ((ent = readdir(dir)) != NULL)
			ft_putendl(ent->d_name);
		closedir(dir);
	}
	else
	{

	}
	return (0);
}