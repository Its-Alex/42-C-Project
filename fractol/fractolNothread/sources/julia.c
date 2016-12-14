/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:04:27 by malexand          #+#    #+#             */
/*   Updated: 2016/12/12 16:30:20 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void	init(t_env *e)
{
	e->m.x = 0;
	e->m.y = 0;
	e->m.x1 = -1.0;
	e->m.x2 = 1.0;
	e->m.y1 = -1.2;
	e->m.y2 = 1.2;
	e->m.i_max = 100;
	e->zoomx = e->width / (e->m.x2 - e->m.x1);
	e->zoomy = e->heigth / (e->m.y2 - e->m.y1);
}

static	void	do_julia(t_env *e)
{
	e->m.c_r = 0.285;
	e->m.c_i = 0.01;
	e->m.z_r = e->m.x / e->zoomx + e->m.x1;
	e->m.z_i = e->m.y / e->zoomy + e->m.y1;;
	e->m.i = 0;
	while (e->m.z_r * e->m.z_r + e->m.z_i * e->m.z_i < 4
		&& e->m.i < e->m.i_max)
	{
		e->m.tmp = e->m.z_r;
		e->m.z_r = e->m.z_r * e->m.z_r - e->m.z_i *
			e->m.z_i + e->m.c_r;
		e->m.z_i = 2 * e->m.z_i * e->m.tmp + e->m.c_i;
		e->m.i = e->m.i + 1;
	}
}

void			julia(t_env *e)
{
	init(e);
	while (e->m.x < e->width)
	{
		e->m.y = 0;
		while (e->m.y < e->width)
		{
			do_julia(e);
			if (e->m.i == e->m.i_max)
				mlx_pixel_put_img(e->m.i * 255 / e->m.i_max , e, e->m.x + e->dx,
					e->m.y + e->dy);
			e->m.y = e->m.y + 1;
		}
		e->m.x = e->m.x + 1;
	}
}
