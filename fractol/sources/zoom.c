/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:23:52 by malexand          #+#    #+#             */
/*   Updated: 2017/01/13 16:17:11 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		zoom_in(t_env *e, int x, int y)
{
	long double		xreal;
	long double		yreal;

	xreal = (x / e->zoomx) + e->x1;
	yreal = (y / e->zoomy) + e->y1;
	e->zoomx *= 1.2;
	e->zoomy *= 1.2;
	e->x1 = (long double)(xreal - (x / e->zoomx));
	e->x2 = xreal + (x / e->zoomx);
	e->y1 = (long double)(yreal - (y / e->zoomy));
	e->y2 = yreal + (y / e->zoomy);
	e->imax += 2;
}

void		zoom_out(t_env *e, int x, int y)
{
	long double		xreal;
	long double		yreal;

	xreal = (x / e->zoomx) + e->x1;
	yreal = (y / e->zoomy) + e->y1;
	e->zoomx /= 1.2;
	e->zoomy /= 1.2;
	e->x1 = (long double)(xreal - (x / e->zoomx));
	e->x2 = xreal + (x / e->zoomx);
	e->y1 = (long double)(yreal - (y / e->zoomy));
	e->y2 = yreal + (y / e->zoomy);
	e->imax -= 2;
}
