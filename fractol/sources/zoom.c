/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:23:52 by malexand          #+#    #+#             */
/*   Updated: 2017/01/09 17:35:33 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		zoom_in(t_env *e, int x, int y)
{
	long double		scalex;
	long double		scaley;
	long double		sx;
	long double		sy;

	scalex = (e->x2 - e->x1);
	scaley = (e->y2 - e->y1);
	sx = x / (e->width / scalex) + e->x1;
	sy = y / (e->heigth / scaley) + e->y1;
	e->x1 = sx - (scalex * 0.4);
	e->x2 = sx + (scalex * 0.4);
	e->y1 = sy - (scaley * 0.4);
	e->y2 = sy + (scaley * 0.4);
	e->zoomx *= 1.25;
	e->zoomy *= 1.25;
	e->imax = e->imax + 2;
}

void		zoom_out(t_env *e, int x, int y)
{
	long double		scalex;
	long double		scaley;
	long double		sx;
	long double		sy;

	scalex = (e->x2 - e->x1);
	scaley = (e->y2 - e->y1);
	sx = x / (e->width / scalex) + e->x1;
	sy = y / (e->heigth / scaley) + e->y1;
	e->x1 = sx - (scalex * 1.4);
	e->x2 = sx + (scalex * 1.4);
	e->y1 = sy - (scaley * 1.4);
	e->y2 = sy + (scaley * 1.4);
	e->zoomx *= 0.75;
	e->zoomy *= 0.75;
	e->imax = e->imax - 2;
}
