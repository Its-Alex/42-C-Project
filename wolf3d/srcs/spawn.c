/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:10:06 by malexand          #+#    #+#             */
/*   Updated: 2017/02/08 12:47:42 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		get_pos_spawn(t_env *e, t_map *map)
{
	int		line;
	int		column;

	line = 0;
	while (line < map->line)
	{
		column = 0;
		while (column < map->column)
		{
			if (map->mapgen[line][column] == 42)
			{
				e->persp->posx = line + 0.5;
				e->persp->posy = column + 0.5;
			}
			column++;
		}
		line++;
	}
}

void			get_spawn(t_env *e, t_map *map)
{
	int		line;
	int		column;
	int		spawn;

	line = 0;
	spawn = 0;
	while (line < map->line)
	{
		column = 0;
		while (column < map->column)
		{
			if (map->mapgen[line][column] == 42)
			{
				if (spawn == 0)
					spawn = 1;
				else
					error(1, 0, "There must be only one spawn point!");
			}
			column++;
		}
		line++;
	}
	if (spawn == 0)
		error(1, 0, "There are no spawn point!");
	get_pos_spawn(e, map);
}

void			gen_spawn(t_env *e, t_map *map)
{
	int		column;
	int		line;

	column = 0;
	line = 0;
	while (map->mapgen[line][column] != 0)
	{
		column = (int)((double)(map->column) * rand() / (RAND_MAX));
		line = (int)((double)(map->line) * rand() / (RAND_MAX));
		if (map->mapgen[line][column] == 0)
		{
			e->persp->posx = line + 0.5;
			e->persp->posy = column + 0.5;
			map->mapgen[line][column] = 42;
			return ;
		}
	}
}
