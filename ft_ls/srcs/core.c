/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 00:41:35 by skyzie            #+#    #+#             */
/*   Updated: 2017/01/18 18:19:11 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ls.h"

int		core(char *flags, char *path)
{
	t_list		*current_lst;

	current_lst = NULL;
	if (path != NULL)
	{
		current_lst = open_dir(path, 1, 1);
		if (current_lst != NULL)
		{
			ft_putendl(ft_strjoin("Path : ", path));
			ft_lstiter(current_lst, putlst);
			ft_putendl("");
			ft_putendl("");
		}
	}
	if (flags == NULL)
		ft_putendl("Flags == NULL");
	while (current_lst != NULL)
	{
		if (ft_strcmp(current_lst->content, ".") != 0 &&
				ft_strcmp(current_lst->content, "..") != 0)
			core(flags, ft_strjoin(ft_strjoin(path, "/"),
				current_lst->content));
		current_lst = current_lst->next;
	}
	return (0);
}
