/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:23:52 by malexand          #+#    #+#             */
/*   Updated: 2017/01/16 14:53:35 by malexand         ###   ########.fr       */
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

void		do_tricorn(t_env *e, t_frac *m)
{
	m->c_r = m->x / e->zoomx + m->x1;
	m->c_i = m->y / e->zoomy + m->y1;
	m->z_r = e->diff_fractx;
	m->z_i = e->diff_fracty;
	m->i = 0;
	while (m->z_r * m->z_r + m->z_i * m->z_i < 4
		&& m->i < e->imax)
	{
		m->tmp = m->z_r;
		m->z_r = m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
		m->z_i = -2 * m->z_i * m->tmp + m->c_i;
		m->i++;
	}
}

void		do_chameleon(t_env *e, t_frac *m)
{
	m->c_r = 0.285 + e->diff_fractx;
	m->c_i = 0.01 + e->diff_fracty;
	m->z_r = m->x / e->zoomx + m->x1;
	m->z_i = m->y / e->zoomy + m->y1;
	m->i = 0;
	while (m->z_r * m->z_r + m->z_i * m->z_i < 4
		&& m->i < e->imax)
	{
		m->tmp = m->z_r;
		m->z_r = m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
		m->z_i = -2 * m->z_i * m->tmp + m->c_i;
		m->i = m->i + 1;
	}
}
