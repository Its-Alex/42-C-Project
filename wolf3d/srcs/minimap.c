/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:29:43 by malexand          #+#    #+#             */
/*   Updated: 2017/02/20 18:02:25 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		fillmmap(t_env *e, t_mmap map)
{
	if (map.x == (int)e->persp->posx && map.y == (int)e->persp->posy)
		mlx_ppi(RGB(255, 255, 255), e->mmap, map.dx, map.dy);
	else if (e->map->mapgen[map.x][map.y] == 2)
		mlx_ppi(RGB(50, 50, 255), e->mmap, map.dx, map.dy);
	else if (e->map->mapgen[map.x][map.y] == 0)
		mlx_ppi(RGB(94, 94, 94), e->mmap, map.dx, map.dy);
	else if (e->map->mapgen[map.x][map.y] == 42)
		mlx_ppi(RGB(255, 0, 0), e->mmap, map.dx, map.dy);
	else if (e->map->mapgen[map.x][map.y] == 1)
		mlx_ppi(RGB(0, 0, 0), e->mmap, map.dx, map.dy);
}

static void		create_square(t_env *e, int x, int y)
{
	int		line;
	int		column;
	t_mmap	map;

	line = 0;
	while (line < 4)
	{
		column = 0;
		while (column < 4)
		{
			map.x = x;
			map.y = y;
			map.dx = y * 4 + line;
			map.dy = x * 4 + column;
			fillmmap(e, map);
			column++;
		}
		line++;
	}
}

void			mmap_ray(t_env *e, int x, int y)
{
	int		line;
	int		column;

	line = 0;
	while (line < 4)
	{
		column = 0;
		while (column < 4)
		{
			mlx_ppi(0x3399FF, e->mmap,
				y * 4 + line, x * 4 + column);
			column++;
		}
		line++;
	}
}

void			minimap(t_env *e)
{
	int		line;
	int		column;

	line = 0;
	while (line < e->map->line)
	{
		column = 0;
		while (column < e->map->column)
		{
			create_square(e, line, column);
			column++;
		}
		line++;
	}
}
