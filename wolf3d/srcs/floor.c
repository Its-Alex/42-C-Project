/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 10:50:21 by malexand          #+#    #+#             */
/*   Updated: 2017/02/21 13:17:28 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		floor_dir()
{
	DIR				*directory;
	t_dir			*ent;

	if ((directory = opendir("floor")))
	{
		while ((ent = readdir(directory)) != NULL)
		{
			if (ent->d_name[0] != '.')
			{
				if (ft_strlen(ent->d_name) != 1)
					error(1, 0, "Floor directory not well formated.");
				if ((ent->d_name[0] < '0' || ent->d_name[0] > '9')
						&& ent->d_name[0] != '.')
					error(1, 0, "Floor files must be named from 0 to 9.");
			}
		}
		closedir(directory);
	}
	else
		error(1, 0, "Unable to find floor directory.");
	return (0);
}

void			floor_up(t_env *e)
{
	int		size;

	if (!e->filename)
		return ;
	if (ft_strnequ("floor/", e->filename, 5) == 0 && floor_dir() == -1)
		return ;
	size = ft_strlen(e->filename);
	if (e->filename[size - 1] > '0')
	{
		e->filename[size - 1] = e->filename[size - 1] - 1;
		ft_putendl(e->filename);
		change_map(e, e->filename);
	}
}

void			floor_down(t_env *e)
{
	int		size;

	if (!e->filename)
		return ;
	if (ft_strnequ("floor/", e->filename, 5) == 0 && floor_dir() != -1)
		return ;
	size = ft_strlen(e->filename);
	if (e->filename[size - 1] < '9')
	{
		e->filename[size - 1] = e->filename[size - 1] + 1;
		ft_putendl(e->filename);
		change_map(e, e->filename);
	}
}
