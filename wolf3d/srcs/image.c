/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:10:53 by malexand          #+#    #+#             */
/*   Updated: 2017/02/28 17:42:08 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_img			*init_img(t_env *e, int width, int height)
{
	t_img		*img;

	if ((img = (t_img *)malloc(sizeof(t_img))) == NULL)
		error(1, 0, "Malloc struct img!");
	img->img = mlx_new_image(e->mlx, width, height);
	if (img->img == NULL)
		error(1, 0, "Init image!");
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_l),
		&(img->endian));
	img->x = width;
	img->y = height;
	return (img);
}

void			mlx_ppi(unsigned int color, t_img *img, int x, int y)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0x00FF00) >> 8);
	b = (color & 0x0000FF);
	if (x >= 0 && x < img->x && y >= 0 && y < img->y)
	{
		if (img->endian == 0)
		{
			img->addr[y * img->size_l + x * img->bpp / 8] = b;
			img->addr[y * img->size_l + x * img->bpp / 8 + 1] = g;
			img->addr[y * img->size_l + x * img->bpp / 8 + 2] = r;
			img->addr[y * img->size_l + x * img->bpp / 8 + 3] = 0;
		}
		else if (img->endian == 1)
		{
			img->addr[y * img->size_l + x * img->bpp / 8] = r;
			img->addr[y * img->size_l + x * img->bpp / 8 + 1] = g;
			img->addr[y * img->size_l + x * img->bpp / 8 + 2] = b;
			img->addr[y * img->size_l + x * img->bpp / 8 + 3] = 0;
		}
	}
}

void			draw_line(t_env *e, t_draw draw)
{
	int		y;
	int		scale;

	y = 0;
	while (y < e->height)
	{
		scale = y * 256 - e->height * 128 + (draw.stop - draw.start) * 128;
		if (y >= draw.stop)
			mlx_ppi(RGB(220, 220, 220), e->view, draw.x, y);
		else if (y >= draw.start)
		{
			if (e->map->mapgen[e->persp->mapx][e->persp->mapy] == 1)
				mlx_ppi(get_color(e->wall, draw.x_tex, ((scale * 64) /
					(draw.stop - draw.start)) / 256), e->view, draw.x, y);
			else
				mlx_ppi(get_color(e->door, draw.x_tex, ((scale * 64) /
					(draw.stop - draw.start)) / 256), e->view, draw.x, y);
		}
		else
			e->view->addr[y * e->view->size_l + draw.x *
				e->view->bpp / 8 + 3] = 255;
		y++;
	}
}

int				put_img(t_env *e)
{
	minimap(e);
	ray_casting(e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->sky->img,
		e->persp->dirx * 75 - 75, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->view->img, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->mmap->img, 15, 15);
	return (0);
}
