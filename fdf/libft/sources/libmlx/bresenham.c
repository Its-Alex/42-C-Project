/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:58:43 by malexand          #+#    #+#             */
/*   Updated: 2016/11/28 15:38:30 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libmlx.h"

static	void		first_case(t_params *params, t_bresenham bresen)
{
	int		e;
	int		count;
	int		inc1;
	int		inc2;

	mlx_pixel_put(params->mlx, params->win, bresen.x, bresen.y, bresen.color);
	e = 2 * bresen.dy - bresen.dx;
	inc1 = 2 * (bresen.dy - bresen.dx);
	inc2 = 2 * bresen.dy;
	count = 0;
	while (count < bresen.dx)
	{
		if (e >= 0)
		{
			bresen.y += bresen.incy;
			e += inc1;
		}
		else
			e += inc2;
		bresen.x += bresen.incx;
		mlx_pixel_put(params->mlx, params->win, bresen.x, bresen.y,
			bresen.color);
		count++;
	}
}

static	void		second_case(t_params *params, t_bresenham bresen)
{
	int		e;
	int		count;
	int		inc1;
	int		inc2;

	mlx_pixel_put(params->mlx, params->win, bresen.x, bresen.y, bresen.color);
	e = 2 * bresen.dx - bresen.dy;
	inc1 = 2 * (bresen.dx - bresen.dy);
	inc2 = 2 * bresen.dx;
	count = 0;
	while (count < bresen.dy)
	{
		if (e >= 0)
		{
			bresen.x += bresen.incx;
			e += inc1;
		}
		else
			e += inc2;
		bresen.y += bresen.incy;
		mlx_pixel_put(params->mlx, params->win, bresen.x, bresen.y,
			bresen.color);
		count++;
	}
}

void				bres(t_params *params, t_point point1, t_point point2)
{
	t_bresenham bresen;

	bresen.color = 0x0000FF;
	bresen.dx = point2.x - point1.x;
	bresen.dy = point2.y - point1.y;
	if (bresen.dx < 0)
		bresen.dx = -bresen.dx;
	if (bresen.dy < 0)
		bresen.dy = -bresen.dy;
	bresen.incx = 1;
	if (point2.x < point1.x)
		bresen.incx = -1;
	bresen.incy = 1;
	if (point2.y < point1.y)
		bresen.incy = -1;
	bresen.x = point1.x;
	bresen.y = point1.y;
	if (bresen.dx > bresen.dy)
		first_case(params, bresen);
	else
		second_case(params, bresen);
}
