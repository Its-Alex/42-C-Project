/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gates.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 12:11:04 by malexand          #+#    #+#             */
/*   Updated: 2017/02/21 16:42:09 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	check_gates(t_map *map)
{
	int		line;
	int		column;

	line = 0;
	while (line < map->line)
	{
		column = 0;
		while (column < map->column)
		{
			if (map->mapgen[line][column] == 4)
				column++;
			column++;
		}
		line++;
	}
}
