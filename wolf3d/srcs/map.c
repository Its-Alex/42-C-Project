/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:55:08 by malexand          #+#    #+#             */
/*   Updated: 2017/02/21 17:05:06 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		fill_map(t_map **map, int column, int line)
{
	int		nbr;

	nbr = (int)(100.0 * rand() / (RAND_MAX));
	if (nbr >= 0 && nbr <= 70)
		(*map)->mapgen[line][column] = 0;
	if (nbr > 70 && nbr <= 100)
		(*map)->mapgen[line][column] = 1;
}

int				check_format(char *str, int count, int nb_elem)
{
	int		save;

	save = 0;
	while (str[count] != '\0')
	{
		if (str[count] != ' ' && str[count] != '\n')
		{
			while (str[count] != ' ' && str[count] != '\n')
				count++;
			nb_elem++;
		}
		if (str[count] == '\n')
		{
			if (save == 0)
				save = nb_elem;
			else
			{
				if (save != nb_elem)
					return (-1);
			}
			nb_elem = 0;
		}
		count++;
	}
	return (0);
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
			if ((column == 0 || line == (*map)->line - 1 || line == 0
					|| column == (*map)->column - 1) && tmp != 4 && tmp != 2)
				(*map)->mapgen[line][column] = 1;
			else if ((tmp >= 0 && tmp <= 2) || tmp == 42 || tmp == 4)
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
			if (column == 0 || column == (*map)->line - 1 || line == 0
					|| line == (*map)->column - 1)
				(*map)->mapgen[line][column] = 1;
			else
				fill_map(map, column, line);
			column++;
		}
		line++;
	}
}

void			change_map(t_env *e, char *filename)
{
	free_tab(e->map->mapget);
	free(e->map);
	e->map = init_map(e, filename);
	mlx_destroy_image(e->mlx, e->mmap->img);
	free(e->mmap);
	e->mmap = init_img(e, e->map->column * 4, e->map->line * 4);
}
