/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:55:08 by malexand          #+#    #+#             */
/*   Updated: 2017/02/06 15:14:42 by malexand         ###   ########.fr       */
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

void			atoi_map(t_map **map)
{
	int		column;
	int		line;
	int		tmp;

	line = 0;
	while (line < (*map)->line)
	{
		column = 0;
		while (column < (*map)->column)
		{
			tmp = ft_atoi((*map)->mapget[line][column]);
			if (column == 0 || line == (*map)->line - 1 || line == 0 || column == (*map)->column - 1)
				(*map)->mapgen[line][column] = 1;
			else if ((tmp >= 0 && tmp <= 2) || tmp == 42)
				(*map)->mapgen[line][column] = tmp;
			else
				(*map)->mapgen[line][column] = 0;
			column++;
		}
		line++;
	}
}

void			get_randmap(t_map **map)
{
	int		column;
	int		line;

	line = 0;
	srand(time(NULL));
	while (line < (*map)->line)
	{
		column = 0;
		while (column < (*map)->column)
		{
			if (column == 0 || column == (*map)->line - 1 || line == 0 || line == (*map)->column - 1)
				(*map)->mapgen[line][column] = 1;
			else
				fill_map(map, column, line);
			column++;
		}
		line++;
	}
}
