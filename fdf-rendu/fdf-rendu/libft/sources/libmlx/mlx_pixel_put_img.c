/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:02:25 by malexand          #+#    #+#             */
/*   Updated: 2016/12/06 18:03:19 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libmlx.h"

void	mlx_pixel_put_img(unsigned long color, t_img *img, int x, int y)
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
	else
	{
		img->addr[y * img->size_l + x * img->bpp / 8] = r;
		img->addr[y * img->size_l + x * img->bpp / 8 + 1] = g;
		img->addr[y * img->size_l + x * img->bpp / 8 + 2] = b;
	}
}
