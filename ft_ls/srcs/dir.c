/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 00:39:56 by skyzie            #+#    #+#             */
/*   Updated: 2017/01/17 13:35:30 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ls.h"

static t_list	*read_dir(DIR *dir, int sneaky)
{
	t_dir			*ent;
	t_list			*list;
	t_list			*tmp;

	list = NULL;
	tmp = NULL;
	while ((ent = readdir(dir)) != NULL)
	{
		if (ent->d_name[0] != '.' || sneaky == 1)
		{
			if (list == NULL)
				list = ft_lstnew(ent->d_name, sizeof(char) *
					(ft_strlen(ent->d_name) + 1));
			else
			{
				tmp = ft_lstnew(ent->d_name, sizeof(char) *
					(ft_strlen(ent->d_name) + 1));
				ft_lstadd(&list, tmp);
			}
		}
	}
	return (list);
}

t_list			*open_dir(char *path, int sneaky)
{
	DIR				*dir;
	t_list			*lst;

	lst = NULL;
	if ((dir = opendir(path)) != NULL)
	{
		lst = read_dir(dir, sneaky);
		closedir(dir);
	}
	return (lst);
}
