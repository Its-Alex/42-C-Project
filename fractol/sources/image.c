/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:10:53 by malexand          #+#    #+#             */
/*   Updated: 2016/12/09 13:46:47 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			mlx_pixel_put_img(unsigned int color, t_img *img, int x, int y)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0x00FF00) >> 8);
	b = (color & 0x0000FF);
	if (img->endian == 0)
	{
		img->addr[y * img->size_l + x * img->bpp / 8] = b;
		img->addr[y * img->size_l + x * img->bpp / 8 + 1] = g;
		img->addr[y * img->size_l + x * img->bpp / 8 + 2] = r;
	}
	else if (img->endian == 1)
	{
		img->addr[y * img->size_l + x * img->bpp / 8] = r;
		img->addr[y * img->size_l + x * img->bpp / 8 + 1] = g;
		img->addr[y * img->size_l + x * img->bpp / 8 + 2] = b;
	}
}

static	void	create_img(t_env *e)
{
	mandelbrot(e);
}

int				put_img(t_env *e)
{
	ft_bzero(e->img->addr, e->img->size_l * e->heigth);
	create_img(e);
	if (e->reload++ == 0)
		e->win = mlx_new_window(e->mlx, e->width, e->heigth, "fractol");
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
