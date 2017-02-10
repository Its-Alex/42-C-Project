/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:10:53 by malexand          #+#    #+#             */
/*   Updated: 2017/02/10 16:03:53 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		mlx_pixel_put_img(unsigned int color, t_img *img, int x, int y)
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
			img->addr[y * img->size_l + x * img->bpp / 8 + 3] = img->opacity;
		}
		else if (img->endian == 1)
		{
			img->addr[y * img->size_l + x * img->bpp / 8] = r;
			img->addr[y * img->size_l + x * img->bpp / 8 + 1] = g;
			img->addr[y * img->size_l + x * img->bpp / 8 + 2] = b;
			img->addr[y * img->size_l + x * img->bpp / 8 + 3] = img->opacity;
		}
	}
}

void		draw_line(t_env *e, int x, int start, int stop,
	unsigned int color)
{
	int		y;

	y = 0;
	while (y < e->heigth)
	{
		if (y >= stop)
			mlx_pixel_put_img(RGB(220, 220, 220), e->view, x, y);
		else if (y >= start)
			mlx_pixel_put_img(color, e->view, x, y);
		else
			mlx_pixel_put_img(RGB(58, 142, 186), e->view, x, y);
		y++;
	}
}

int			put_img(t_env *e)
{
	minimap(e);
	ray_casting(e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->view->img, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->mmap->img, 15, 15);
	return (0);
}
