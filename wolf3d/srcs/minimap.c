/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:29:43 by malexand          #+#    #+#             */
/*   Updated: 2017/02/10 16:09:59 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		create_square(t_env *e, int x, int y)
{
	int		line;
	int		column;

	line = 0;
	while (line < 4)
	{
		column = 0;
		while (column < 4)
		{
			if (x == (int)e->persp->posx && y == (int)e->persp->posy)
				mlx_pixel_put_img(RGB(255, 255, 255), e->mmap,
					y * 4 + line, x * 4 + column);
			else if (e->map->mapgen[x][y] == 2)
				mlx_pixel_put_img(RGB(50, 50, 255), e->mmap,
					y * 4 + line, x * 4 + column);
			else if (e->map->mapgen[x][y] == 0)
				mlx_pixel_put_img(RGB(94, 94, 94), e->mmap,
					y * 4 + line, x * 4 + column);
			else if (e->map->mapgen[x][y] == 42)
				mlx_pixel_put_img(RGB(255, 0, 0), e->mmap,
					y * 4 + line, x * 4 + column);
			else if (e->map->mapgen[x][y] == 1)
				mlx_pixel_put_img(RGB(0, 0, 0), e->mmap,
					y * 4 + line, x * 4 + column);
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
			mlx_pixel_put_img(0x3399FF, e->mmap,
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
