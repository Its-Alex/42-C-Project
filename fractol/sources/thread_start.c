/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:33:51 by malexand          #+#    #+#             */
/*   Updated: 2017/01/13 16:28:26 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			init_fract(t_env *e, t_frac *m)
{
	m->x1 = e->x1 + e->dx;
	m->x2 = e->x2 - e->dx;
	m->y1 = e->y1 + e->dy;
	m->y2 = e->y2 - e->dy;
}

void			*hg(void *env)
{
	t_env		*e;
	t_frac		m;

	e = env;
	init_fract(e, &m);
	while (m.x < e->width / 4)
	{
		m.y = 0;
		while (m.y < e->heigth / 2)
		{
			do_fract(e, &m);
			if (e->color_mod == 1)
				mlx_pixel_put_img((int)((m.i * e->color / e->imax)),
					e, e->dx + m.x, e->dy + m.y);
			else if (m.i != e->imax && e->color_mod == 0)
				mlx_pixel_put_img((int)((m.i * e->color / e->imax)),
				e, e->dx + m.x, e->dy + m.y);
			m.y = m.y + 1;
		}
		m.x = m.x + 1;
	}
	pthread_exit(NULL);
}

void			*hg1(void *env)
{
	t_env		*e;
	t_frac		m;

	e = env;
	init_fract(e, &m);
	m.x = e->width / 4;
	while (m.x < e->width / 4 * 2)
	{
		m.y = 0;
		while (m.y < e->heigth / 2)
		{
			do_fract(e, &m);
			if (e->color_mod == 1)
				mlx_pixel_put_img((int)((m.i * e->color / e->imax)),
					e, e->dx + m.x, e->dy + m.y);
			else if (m.i != e->imax && e->color_mod == 0)
				mlx_pixel_put_img((int)((m.i * e->color / e->imax)),
				e, e->dx + m.x, e->dy + m.y);
			m.y = m.y + 1;
		}
		m.x = m.x + 1;
	}
	pthread_exit(NULL);
}

void			*hd(void *env)
{
	t_env		*e;
	t_frac		m;

	e = env;
	init_fract(e, &m);
	m.x = e->width / 2;
	while (m.x < e->width / 4 * 3)
	{
		m.y = 0;
		while (m.y < e->heigth / 2)
		{
			do_fract(e, &m);
			if (e->color_mod == 1)
				mlx_pixel_put_img((int)((m.i * e->color / e->imax)),
					e, e->dx + m.x, e->dy + m.y);
			else if (m.i != e->imax && e->color_mod == 0)
				mlx_pixel_put_img((int)((m.i * e->color / e->imax)),
				e, e->dx + m.x, e->dy + m.y);
			m.y = m.y + 1;
		}
		m.x = m.x + 1;
	}
	pthread_exit(NULL);
}

void			*hd1(void *env)
{
	t_env		*e;
	t_frac		m;

	e = env;
	init_fract(e, &m);
	m.x = e->width / 4 * 3;
	while (m.x <= e->width)
	{
		m.y = 0;
		while (m.y < e->heigth / 2)
		{
			do_fract(e, &m);
			if (e->color_mod == 1)
				mlx_pixel_put_img((int)((m.i * e->color / e->imax)),
					e, e->dx + m.x, e->dy + m.y);
			else if (m.i != e->imax && e->color_mod == 0)
				mlx_pixel_put_img((int)((m.i * e->color / e->imax)),
				e, e->dx + m.x, e->dy + m.y);
			m.y = m.y + 1;
		}
		m.x = m.x + 1;
	}
	pthread_exit(NULL);
}
