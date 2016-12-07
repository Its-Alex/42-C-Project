/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:58:43 by malexand          #+#    #+#             */
/*   Updated: 2016/12/06 18:03:22 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libmlx.h"

/*
**	Tracer de Bresenham
*/

static	t_bres	init(t_mlx *mlx, t_point *p1, t_point *p2)
{
	t_bres		bres;

	if (mlx->color == 1)
		bres.color = 0x0000FF;
	if (mlx->color == 2)
		bres.color = 0x00FF00;
	if (mlx->color == 3)
		bres.color = 0xFF0000;
	if (mlx->color == 4)
		bres.color = 0xFFFFFF;
	bres.x0 = p1->px;
	bres.y0 = p1->py;
	bres.x1 = p2->px;
	bres.y1 = p2->py;
	bres.dx = ((p2->px - bres.x0) < 0) ? -(p2->px - bres.x0) : p2->px - bres.x0;
	bres.sx = bres.x0 < p2->px ? 1 : -1;
	bres.dy = ((p2->py - p1->py) < 0) ? -(p2->py - p1->py) : p2->py - p1->py;
	bres.sy = p1->py < p2->py ? 1 : -1;
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
		if (bres.x0 < mlx->width && bres.y0 < mlx->heigth &&
				bres.x0 > 0 && bres.y0 > 0)
			mlx_pixel_put_img(bres.color, mlx->img, bres.x0, bres.y0);
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
