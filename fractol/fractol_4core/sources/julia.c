/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:04:27 by malexand          #+#    #+#             */
/*   Updated: 2016/12/13 14:25:40 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			julia(t_env *e)
{
	t_frac		m;

	init_julia(e, &m);
	while (m.x < e->width)
	{
		m.y = 0;
		while (m.y < e->heigth)
		{
			do_julia(e, &m);
			if (m.i == m.i_max)
				mlx_pixel_put_img(m.i * 255 / m.i_max, e, m.x + e->dx,
					m.y + e->dy);
			m.y = m.y + 1;
		}
		m.x = m.x + 1;
	}
}
