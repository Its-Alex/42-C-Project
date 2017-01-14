/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 22:42:09 by skyzie            #+#    #+#             */
/*   Updated: 2017/01/13 23:28:45 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		read_dir(char *path)
{
	DIR		*dir;
	t_dir	*ent;
	t_stat	*stats;

	stats = NULL;
	if ((dir = opendir(path)))
	{
		while ((ent = readdir(dir)) != NULL)
			ft_putendl(ent->d_name);
		closedir(dir);
	}
	stat(path, stats);
	ft_putnbr(stats->st_size);
	return (0);
}