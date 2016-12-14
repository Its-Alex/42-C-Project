/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:10:53 by malexand          #+#    #+#             */
/*   Updated: 2016/12/13 11:20:59 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			mlx_pixel_put_img(unsigned int color, t_env *e, int x, int y)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0x00FF00) >> 8);
	b = (color & 0x0000FF);
	if (x >= 0 && x < e->width && y >= 0 && y < e->heigth)
	{
		if (e->img->endian == 0)
		{
			e->img->addr[y * e->img->size_l + x * e->img->bpp / 8] = b;
			e->img->addr[y * e->img->size_l + x * e->img->bpp / 8 + 1] = g;
			e->img->addr[y * e->img->size_l + x * e->img->bpp / 8 + 2] = r;
		}
		else if (e->img->endian == 1)
		{
			e->img->addr[y * e->img->size_l + x * e->img->bpp / 8] = r;
			e->img->addr[y * e->img->size_l + x * e->img->bpp / 8 + 1] = g;
			e->img->addr[y * e->img->size_l + x * e->img->bpp / 8 + 2] = b;
		}
	}
}

static	void	create_img(t_env *e)
{
	mandelbrot(e);
	// julia(e);
}

int				put_img(t_env *e)
{
	ft_bzero(e->img->addr, e->img->size_l * e->heigth);
	create_img(e);
	if (e->reload++ == 0)
		e->win = mlx_new_window(e->mlx, e->width, e->heigth, "fractol");
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
	return (0);
}
