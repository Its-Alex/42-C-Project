/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_frac.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:23:21 by malexand          #+#    #+#             */
/*   Updated: 2016/12/15 17:27:06 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	do_mandel(t_env *e, t_frac *m)
{
	m->c_r = m->x / e->zoomx + m->x1;
	m->c_i = m->y / e->zoomy + m->y1;
	m->z_r = 0;
	m->z_i = 0;
	m->i = 0;
	while (m->z_r * m->z_r + m->z_i * m->z_i < 4
		&& m->i < m->i_max)
	{
		m->tmp = m->z_r;
		m->z_r = m->z_r * m->z_r - m->z_i *
			m->z_i + m->c_r;
		m->z_i = 2 * m->z_i * m->tmp + m->c_i;
		m->i = m->i + 1;
	}
}

void	do_julia(t_env *e, t_frac *m)
{
	m->c_r = 0.285;
	m->c_i = 0.01;
	m->z_r = m->x / e->zoomx + m->x1;
	m->z_i = m->y / e->zoomy + m->y1;
	m->i = 0;
	while (m->z_r * m->z_r + m->z_i * m->z_i < 4
		&& m->i < m->i_max)
	{
		m->tmp = m->z_r;
		m->z_r = m->z_r * m->z_r - m->z_i *
			m->z_i + m->c_r;
		m->z_i = 2 * m->z_i * m->tmp + m->c_i;
		m->i = m->i + 1;
	}
}
