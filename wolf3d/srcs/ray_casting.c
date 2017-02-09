/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:00:19 by malexand          #+#    #+#             */
/*   Updated: 2017/02/09 14:00:24 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		draw_line(t_env *e, int x, int start, int stop, unsigned int color)
{
	int		y;

	y = 0;
	while (y < e->heigth)
	{
		if (y >= stop)
			mlx_pixel_put_img(RGB(96, 96, 96), e->view, x, y);
		else if (y >= start)
			mlx_pixel_put_img(color, e->view, x, y);
		else
			mlx_pixel_put_img(RGB(58, 142, 186), e->view, x, y);
		y += 1;
	}
}

void		ray_casting(t_env *e)
{
	
}
