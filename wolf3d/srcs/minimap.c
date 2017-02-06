/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:29:43 by malexand          #+#    #+#             */
/*   Updated: 2017/02/06 16:36:07 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		create_square(t_env *e, int x, int y)
{
	int		line;
	int		column;

	line = 0;
	while (line < 3)
	{
		column = 0;
		while (column < 3)
		{
			if (x == (int)e->persp->posx && y == (int)e->persp->posy)
				mlx_pixel_put_img(RGB(255, 255, 255), e->mmap,
					y * 3 + line, x * 3 + column);
			else if (e->map->mapgen[x][y] == 0)
				mlx_pixel_put_img(RGB(94, 94, 94), e->mmap,
					y * 3 + line, x * 3 + column);
			else if (e->map->mapgen[x][y] == 42)
				mlx_pixel_put_img(RGB(255, 0, 0), e->mmap,
					y * 3 + line, x * 3 + column);
			else if (e->map->mapgen[x][y] == 1 || e->map->mapgen[x][y] == 2)
				mlx_pixel_put_img(RGB(0, 0, 0), e->mmap,
					y * 3 + line, x * 3 + column);
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
