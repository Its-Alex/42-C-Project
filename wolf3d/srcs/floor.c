/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 10:50:21 by malexand          #+#    #+#             */
/*   Updated: 2017/02/22 11:37:47 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		floor_format(t_dir *ent)
{
	if (ft_strlen(ent->d_name) != 1)
		error(1, 0, "Floor directory not well formated.");
	if ((ent->d_name[0] < '0' || ent->d_name[0] > '9')
			&& ent->d_name[0] != '.')
		error(1, 0, "Floor files must be named from 0 to 9.");
}

static int		floor_dir(int nb)
{
	DIR				*directory;
	t_dir			*ent;
	int				save;

	save = 0;
	if ((directory = opendir("floor")))
	{
		while ((ent = readdir(directory)) != NULL)
		{
			if (ent->d_name[0] != '.')
			{
				floor_format(ent);
				if (ft_atoi(&ent->d_name[0]) == nb)
					save = 1;
			}
		}
		closedir(directory);
	}
	else
		error(1, 0, "Unable to find floor directory.");
	if (save == 1)
		return (0);
	else
		return (-1);
}

void			floor_up(t_env *e)
{
	int		size;

	size = ft_strlen(e->filename);
	if (floor_dir(ft_atoi(&e->filename[size - 1]) - 1) == -1)
		return ;
	if (e->filename[size - 1] > '0')
	{
		e->filename[size - 1] = e->filename[size - 1] - 1;
		change_map(e, e->filename);
	}
}

void			floor_down(t_env *e)
{
	int		size;

	size = ft_strlen(e->filename);
	if (floor_dir(ft_atoi(&e->filename[size - 1]) + 1) == -1)
		return ;
	if (e->filename[size - 1] < '9')
	{
		e->filename[size - 1] = e->filename[size - 1] + 1;
		change_map(e, e->filename);
	}
}

void			check_floor(t_env *e)
{
	if (e->filename == NULL)
		return ;
	if (ft_strnequ("floor/", e->filename, 5) == 0)
		return ;
	if (e->map->mapgen[(int)floor(e->persp->posx + e->persp->dirx * 0.05 * 5)]
			[(int)floor(e->persp->posy)] == 2 || e->map->mapgen
			[(int)floor(e->persp->posx)][(int)floor(e->persp->posy
			+ e->persp->diry * 0.05 * 5)] == 2)
		floor_up(e);
	if (e->map->mapgen[(int)floor(e->persp->posx + e->persp->dirx * 0.05 * 5)]
			[(int)floor(e->persp->posy)] == 4 || e->map->mapgen
			[(int)floor(e->persp->posx)][(int)floor(e->persp->posy
			+ e->persp->diry * 0.05 * 5)] == 4)
		floor_down(e);
}
