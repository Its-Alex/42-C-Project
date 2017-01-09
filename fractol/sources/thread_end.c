/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:34:52 by malexand          #+#    #+#             */
/*   Updated: 2017/01/09 18:17:50 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			*bg(void *env)
{
	t_env		*e;
	t_frac		m;

	e = env;
	init_fract(e, &m);
	m.x = 0;
	while (m.x < e->width / 4)
	{
		m.y = e->heigth / 2;
		while (m.y < e->heigth)
		{
			do_fract(e, &m);
			if (m.i != e->imax)
				mlx_pixel_put_img((int)((m.i * 255 / e->imax)) << 16
					, e, e->dx + m.x, e->dy + m.y);
			m.y = m.y + 1;
		}
		m.x = m.x + 1;
	}
	pthread_exit(NULL);
}

void			*bg1(void *env)
{
	t_env		*e;
	t_frac		m;

	e = env;
	init_fract(e, &m);
	m.x = e->width / 4;
	while (m.x < e->width / 2)
	{
		m.y = e->heigth / 2;
		while (m.y <= e->heigth)
		{
			do_fract(e, &m);
			if (m.i != e->imax)
				mlx_pixel_put_img((int)((m.i * 255 / e->imax)) << 16
					, e, e->dx + m.x, e->dy + m.y);
			m.y = m.y + 1;
		}
		m.x = m.x + 1;
	}
	pthread_exit(NULL);
}

void			*bd(void *env)
{
	t_env		*e;
	t_frac		m;

	e = env;
	init_fract(e, &m);
	m.x = e->width / 2;
	while (m.x < e->width / 4 * 3)
	{
		m.y = e->heigth / 2;
		while (m.y <= e->heigth)
		{
			do_fract(e, &m);
			if (m.i != e->imax)
				mlx_pixel_put_img((int)((m.i * 255 / e->imax)) << 16
					, e, e->dx + m.x, e->dy + m.y);
			m.y = m.y + 1;
		}
		m.x = m.x + 1;
	}
	pthread_exit(NULL);
}

void			*bd1(void *env)
{
	t_env		*e;
	t_frac		m;

	e = env;
	init_fract(e, &m);
	m.x = e->width / 4 * 3;
	while (m.x <= e->width)
	{
		m.y = e->heigth / 2;
		while (m.y <= e->heigth)
		{
			do_fract(e, &m);
			if (m.i != e->imax)
				mlx_pixel_put_img((int)((m.i * 255 / e->imax)) << 16
					, e, e->dx + m.x, e->dy + m.y);
			m.y = m.y + 1;
		}
		m.x = m.x + 1;
	}
	pthread_exit(NULL);
}
