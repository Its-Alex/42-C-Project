/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:22:08 by malexand          #+#    #+#             */
/*   Updated: 2017/01/03 16:51:52 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_mandel(t_env *e, t_frac *m)
{
	m->x = 0;
	m->y = 0;
	m->x1 = -2.1 + e->dx;
	m->x2 = 0.6 + e->dx;
	m->y1 = -1.2 + e->dy;
	m->y2 = 1.2 + e->dy;
	e->zoomx = (e->width / (m->x2 - m->x1) + e->dx) * e->zoom;
	e->zoomy = (e->heigth / (m->y2 - m->y1) + e->dy) * e->zoom;
}

void	init_julia(t_env *e, t_frac *m)
{
	m->x = 0;
	m->y = 0;
	m->x1 = -1.0;
	m->x2 = 1.0;
	m->y1 = -1.2;
	m->y2 = 1.2;
	e->zoomx = e->width / (m->x2 - m->x1);
	e->zoomy = e->heigth / (m->y2 - m->y1);
}
