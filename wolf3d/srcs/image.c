/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:10:53 by malexand          #+#    #+#             */
/*   Updated: 2017/01/31 15:12:23 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			mlx_pixel_put_img(unsigned int color, t_env *e, int x, int y)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0x00FF00) >> 8);
	b = (color & 0x0000FF);
	if (x >= 0 && x < e->w && y >= 0 && y < e->h)
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

int				put_img(t_env *e)
{
	ft_bzero(e->img->addr, e->img->size_l * e->h);
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
	return (0);
}
