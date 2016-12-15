/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:01:37 by malexand          #+#    #+#             */
/*   Updated: 2016/12/14 17:39:57 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			mlx_pixel_put_img(unsigned long color, t_mlx *mlx, int x, int y)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0x00FF00) >> 8);
	b = (color & 0x0000FF);
	if (mlx->img->endian == 0 && x >= 0 && x < mlx->width &&
		y >= 0 && y < mlx->heigth)
	{
		mlx->img->addr[y * mlx->img->size_l + x * mlx->img->bpp / 8] = b;
		mlx->img->addr[y * mlx->img->size_l + x * mlx->img->bpp / 8 + 1] = g;
		mlx->img->addr[y * mlx->img->size_l + x * mlx->img->bpp / 8 + 2] = r;
	}
	else if (mlx->img->endian == 1 && x >= 0 && x < mlx->width &&
		y >= 0 && y < mlx->heigth)
	{
		mlx->img->addr[y * mlx->img->size_l + x * mlx->img->bpp / 8] = r;
		mlx->img->addr[y * mlx->img->size_l + x * mlx->img->bpp / 8 + 1] = g;
		mlx->img->addr[y * mlx->img->size_l + x * mlx->img->bpp / 8 + 2] = b;
	}
}

/*
**	Tracer de Bresenham
*/

static	t_bres	init(t_mlx *mlx, t_point *p1, t_point *p2)
{
	t_bres		bres;

	if (p1->z == mlx->color && p2->z == mlx->color)
		bres.color = 0x000000;
	else
		bres.color = 0xFFFFFF;
	bres.x0 = p1->px;
	bres.y0 = p1->py;
	bres.x1 = p2->px;
	bres.y1 = p2->py;
	bres.dx = ((bres.x1 - bres.x0) < 0)
		? -(bres.x1 - bres.x0) : bres.x1 - bres.x0;
	bres.sx = (bres.x0 < bres.x1) ? 1 : -1;
	bres.dy = ((bres.y1 - bres.y0) < 0)
		? -(bres.y1 - bres.y0) : bres.y1 - bres.y0;
	bres.sy = (bres.y0 < bres.y1) ? 1 : -1;
	bres.err = ((bres.dx > bres.dy) ? bres.dx : -bres.dy) / 2;
	bres.e2 = 0;
	return (bres);
}

void			mlx_put_line(t_mlx *mlx, t_point *p1, t_point *p2)
{
	t_bres		bres;

	bres = init(mlx, p1, p2);
	while (1)
	{
		mlx_pixel_put_img(bres.color, mlx, bres.x0, bres.y0);
		if (bres.x0 == bres.x1 && bres.y0 == bres.y1)
			break ;
		bres.e2 = bres.err;
		if (bres.e2 > -bres.dx)
		{
			bres.err -= bres.dy;
			bres.x0 += bres.sx;
		}
		if (bres.e2 < bres.dy)
		{
			bres.err += bres.dx;
			bres.y0 += bres.sy;
		}
	}
}
