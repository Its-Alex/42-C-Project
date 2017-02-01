/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:55:08 by malexand          #+#    #+#             */
/*   Updated: 2017/02/01 16:26:08 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		fill_map(t_map **map, int column, int line)
{
	int		nbr;

	nbr = (int)(100.0 * rand() / (RAND_MAX));
	if (nbr >= 0 && nbr <= 70)
		(*map)->mapgen[line][column] = 0;
	if (nbr > 70 && nbr <= 95)
		(*map)->mapgen[line][column] = 1;
	if (nbr > 95 && nbr <= 100)
		(*map)->mapgen[line][column] = 2;
}

void			atoi_map(t_map **map, int x, int y)
{
	int		column;
	int		line;

	line = 0;
	srand(time(NULL));
	while (line < y)
	{
		column = 0;
		while (column < x)
		{
			if (column == 0 || column == x - 1 || line == 0 || line == y - 1)
				(*map)->mapgen[line][column] = 1;
			else
				(*map)->mapgen[line][column] =
					ft_atoi((*map)->mapget[line][column]);
			column++;
		}
		line++;
	}
}

void			get_randmap(t_map **map, int x, int y)
{
	int		column;
	int		line;

	line = 0;
	srand(time(NULL));
	while (line < y)
	{
		column = 0;
		while (column < x)
		{
			if (column == 0 || column == x - 1 || line == 0 || line == y - 1)
				(*map)->mapgen[line][column] = 1;
			else
				fill_map(map, column, line);
			column++;
		}
		line++;
	}
}
