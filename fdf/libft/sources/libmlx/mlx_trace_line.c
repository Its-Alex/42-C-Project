/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_trace_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:58:43 by malexand          #+#    #+#             */
/*   Updated: 2016/11/30 16:37:24 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libmlx.h"

/*
**	Tracer de Bresenham
*/

static	void		first_case(t_mlx *mlx, t_bresenham bresen)
{
	int		e;
	int		count;
	int		inc1;
	int		inc2;

	mlx_pixel_put_img(bresen.color, mlx->img, bresen.x, bresen.y);
	e = 2 * bresen.dy - bresen.dx;
	inc1 = 2 * (bresen.dy - bresen.dx);
	inc2 = 2 * bresen.dy;
	count = 0;
	while (count < bresen.dx)
	{
		bresen.color += mlx->degrad;
		if (e >= 0)
		{
			bresen.y += bresen.incy;
			e += inc1;
		}
		else
			e += inc2;
		bresen.x += bresen.incx;
		mlx_pixel_put_img(bresen.color, mlx->img, bresen.x, bresen.y);
		count++;
	}
}

static	void		second_case(t_mlx *mlx, t_bresenham bresen)
{
	int		e;
	int		count;
	int		inc1;
	int		inc2;

	mlx_pixel_put_img(bresen.color, mlx->img, bresen.x, bresen.y);
	e = 2 * bresen.dx - bresen.dy;
	inc1 = 2 * (bresen.dx - bresen.dy);
	inc2 = 2 * bresen.dx;
	count = 0;
	while (count < bresen.dy)
	{
		bresen.color += mlx->degrad;
		if (e >= 0)
		{
			bresen.x += bresen.incx;
			e += inc1;
		}
		else
			e += inc2;
		bresen.y += bresen.incy;
		mlx_pixel_put_img(bresen.color, mlx->img, bresen.x, bresen.y);
		count++;
	}
}

void				mlx_trace_line(t_mlx *mlx, t_point p1, t_point p2)
{
	t_bresenham bresen;

	bresen.color = p1.color;
	bresen.dx = p2.x - p1.x;
	bresen.dy = p2.y - p1.y;
	if (bresen.dx < 0)
		bresen.dx = -bresen.dx;
	if (bresen.dy < 0)
		bresen.dy = -bresen.dy;
	bresen.incx = 1;
	if (p2.x < p1.x)
		bresen.incx = -1;
	bresen.incy = 1;
	if (p2.y < p1.y)
		bresen.incy = -1;
	bresen.x = p1.x;
	bresen.y = p1.y;
	if (bresen.dx > bresen.dy)
		first_case(mlx, bresen);
	else
		second_case(mlx, bresen);
}
