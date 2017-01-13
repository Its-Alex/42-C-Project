/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_frac.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:23:21 by malexand          #+#    #+#             */
/*   Updated: 2017/01/13 16:02:59 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	do_mandel(t_env *e, t_frac *m)
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
		m->z_i = 2 * m->z_i * m->tmp + m->c_i;
		m->i = m->i + 1;
	}
}

void	do_julia(t_env *e, t_frac *m)
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
		m->z_i = 2 * m->z_i * m->tmp + m->c_i;
		m->i = m->i + 1;
	}
}

void	do_burningship(t_env *e, t_frac *m)
{
	m->c_r = m->x / e->zoomx + m->x1;
	m->c_i = m->y / e->zoomy + m->y1;
	m->z_r = e->diff_fractx;
	m->z_i = e->diff_fracty;
	m->i = 0;
	while ((m->z_r * m->z_r) + (m->z_i * m->z_i) < 4 && m->i < e->imax)
	{
		m->tmp = m->z_r;
		m->z_r = (m->z_r * m->z_r) - (m->z_i * m->z_i) + m->c_r;
		m->z_i = 2 * fabsl(m->z_i * m->tmp) + m->c_i;
		m->i = m->i + 1;
	}
}

void	do_douady(t_env *e, t_frac *m)
{
	m->c_r = -0.132570 + e->diff_fractx;
	m->c_i = -0.766400 + e->diff_fracty;
	m->z_r = m->x / e->zoomx + m->x1;
	m->z_i = m->y / e->zoomy + m->y1;
	m->i = 0;
	while (m->z_r * m->z_r + m->z_i * m->z_i < 4
		&& m->i < e->imax)
	{
		m->tmp = m->z_r;
		m->z_r = m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
		m->z_i = 2 * m->z_i * m->tmp + m->c_i;
		m->i = m->i + 1;
	}
}

void	do_fract(t_env *e, t_frac *m)
{
	if (ft_strcmp(e->av[1], "Mandelbrot") == 0)
		do_mandel(e, m);
	else if (ft_strcmp(e->av[1], "Julia") == 0)
		do_julia(e, m);
	else if (ft_strcmp(e->av[1], "BurningShip") == 0)
		do_burningship(e, m);
	else if (ft_strcmp(e->av[1], "Douady") == 0)
		do_douady(e, m);
}
