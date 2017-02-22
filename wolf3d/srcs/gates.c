/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gates.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 12:11:04 by malexand          #+#    #+#             */
/*   Updated: 2017/02/22 11:36:20 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		check_back(t_map *map)
{
	int		line;
	int		column;
	int		save;

	line = 0;
	save = 0;
	while (line < map->line)
	{
		column = 0;
		while (column < map->column)
		{
			if (map->mapgen[line][column] == 4)
				save += 1;
			column++;
		}
		line++;
	}
	if (save <= 4)
		return (0);
	else
		return (-1);
}

static int		check_forward(t_map *map)
{
	int		line;
	int		column;
	int		save;

	line = 0;
	save = 0;
	while (line < map->line)
	{
		column = 0;
		while (column < map->column)
		{
			if (map->mapgen[line][column] == 2)
				save += 1;
			column++;
		}
		line++;
	}
	if (save <= 4)
		return (0);
	else
		return (-1);
}

void			check_gates(t_map *map)
{
	if (check_forward(map) == -1)
		error(1, 0, "Too many gates!");
	if (check_back(map) == -1)
		error(1, 0, "Too many gates!");
}
