/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:32:13 by malexand          #+#    #+#             */
/*   Updated: 2017/01/09 14:01:37 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			*mandelbrot_hg(void *env)
{
	t_env		*e;
	t_frac		m;

	e = env;
	init_mandel(e, &m);
	while (m.x < e->width / 4)
	{
		m.y = 0;
		while (m.y < e->heigth / 2)
		{
			do_mandel(e, &m);
			if (m.i != e->imax)
				mlx_pixel_put_img((int)((m.i * 255 / e->imax)) << 16
					, e, e->dx + m.x, e->dy + m.y);
			m.y = m.y + 1;
		}
		m.x = m.x + 1;
	}
	pthread_exit(NULL);
}

void			*mandelbrot_hg1(void *env)
{
	t_env		*e;
	t_frac		m;

	e = env;
	init_mandel(e, &m);
	m.x = e->width / 4;
	while (m.x < e->width / 4 * 2)
	{
		m.y = 0;
		while (m.y < e->heigth / 2)
		{
			do_mandel(e, &m);
			if (m.i != e->imax)
				mlx_pixel_put_img((int)((m.i * 255 / e->imax)) << 16
					, e, e->dx + m.x, e->dy + m.y);
			m.y = m.y + 1;
		}
		m.x = m.x + 1;
	}
	pthread_exit(NULL);
}

void			*mandelbrot_hd(void *env)
{
	t_env		*e;
	t_frac		m;

	e = env;
	init_mandel(e, &m);
	m.x = e->width / 2;
	while (m.x < e->width / 4 * 3)
	{
		m.y = 0;
		while (m.y < e->heigth / 2)
		{
			do_mandel(e, &m);
			if (m.i != e->imax)
				mlx_pixel_put_img((int)((m.i * 255 / e->imax)) << 16
					, e, e->dx + m.x, e->dy + m.y);
			m.y = m.y + 1;
		}
		m.x = m.x + 1;
	}
	pthread_exit(NULL);
}

void			*mandelbrot_hd1(void *env)
{
	t_env		*e;
	t_frac		m;

	e = env;
	init_mandel(e, &m);
	m.x = e->width / 4 * 3;
	while (m.x <= e->width)
	{
		m.y = 0;
		while (m.y < e->heigth / 2)
		{
			do_mandel(e, &m);
			if (m.i != e->imax)
				mlx_pixel_put_img((int)((m.i * 255 / e->imax)) << 16
					, e, e->dx + m.x, e->dy + m.y);
			m.y = m.y + 1;
		}
		m.x = m.x + 1;
	}
	pthread_exit(NULL);
}

void			*mandelbrot_bg(void *env)
{
	t_env		*e;
	t_frac		m;

	e = env;
	init_mandel(e, &m);
	m.x = 0;
	while (m.x < e->width / 4)
	{
		m.y = e->heigth / 2;
		while (m.y < e->heigth)
		{
			do_mandel(e, &m);
			if (m.i != e->imax)
				mlx_pixel_put_img((int)((m.i * 255 / e->imax)) << 16
					, e, e->dx + m.x, e->dy + m.y);
			m.y = m.y + 1;
		}
		m.x = m.x + 1;
	}
	pthread_exit(NULL);
}

void			*mandelbrot_bg1(void *env)
{
	t_env		*e;
	t_frac		m;

	e = env;
	init_mandel(e, &m);
	m.x = e->width / 4;
	while (m.x < e->width / 2)
	{
		m.y = e->heigth / 2;
		while (m.y <= e->heigth)
		{
			do_mandel(e, &m);
			if (m.i != e->imax)
				mlx_pixel_put_img((int)((m.i * 255 / e->imax)) << 16
					, e, e->dx + m.x, e->dy + m.y);
			m.y = m.y + 1;
		}
		m.x = m.x + 1;
	}
	pthread_exit(NULL);
}

void			*mandelbrot_bd(void *env)
{
	t_env		*e;
	t_frac		m;

	e = env;
	init_mandel(e, &m);
	m.x = e->width / 2;
	while (m.x < e->width / 4 * 3)
	{
		m.y = e->heigth / 2;
		while (m.y <= e->heigth)
		{
			do_mandel(e, &m);
			if (m.i != e->imax)
				mlx_pixel_put_img((int)((m.i * 255 / e->imax)) << 16
					, e, e->dx + m.x, e->dy + m.y);
			m.y = m.y + 1;
		}
		m.x = m.x + 1;
	}
	pthread_exit(NULL);
}

void			*mandelbrot_bd1(void *env)
{
	t_env		*e;
	t_frac		m;

	e = env;
	init_mandel(e, &m);
	m.x = e->width / 4 * 3;
	while (m.x <= e->width)
	{
		m.y = e->heigth / 2;
		while (m.y <= e->heigth)
		{
			do_mandel(e, &m);
			if (m.i != e->imax)
				mlx_pixel_put_img((int)((m.i * 255 / e->imax)) << 16
					, e, e->dx + m.x, e->dy + m.y);
			m.y = m.y + 1;
		}
		m.x = m.x + 1;
	}
	pthread_exit(NULL);
}
