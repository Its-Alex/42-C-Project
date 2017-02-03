/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:29:43 by malexand          #+#    #+#             */
/*   Updated: 2017/02/03 17:53:06 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		create_square(t_env *e, int y, int x)
{
	int		line;
	int		column;

	line = 0;
	while (line < 6)
	{
		column = 0;
		while (column < 6)
		{
			if (x == (int)e->persp->posx && y == (int)e->persp->posy)
				mlx_pixel_put_img(RGB(255, 255, 255), e->mmap,
					x * 6 + line, y * 6 + column);
			else if (e->map->mapgen[x][y] == 0)
				mlx_pixel_put_img(RGB(94, 94, 94), e->mmap,
					x * 6 + line, y * 6 + column);
			else if (e->map->mapgen[x][y] == 1 || e->map->mapgen[x][y] == 2)
				mlx_pixel_put_img(RGB(0, 0, 0), e->mmap,
					x * 6 + line, y * 6 + column);
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
	while (line < e->map->x)
	{
		column = 0;
		while (column < e->map->y)
		{
			create_square(e, line, column);
			column++;
		}
		line++;
	}
}
