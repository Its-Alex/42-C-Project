/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:37:18 by malexand          #+#    #+#             */
/*   Updated: 2017/01/16 14:45:16 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				mouse_button(int button, int x, int y, t_env *e)
{
	if (x < 0 || y < 0)
		return (0);
	if (button == 1 || button == 5)
		zoom_in(e, x, y);
	if (button == 2 || button == 4)
		zoom_out(e, x, y);
	return (0);
}

int				mouse_motion(int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0 && x <= e->width && x <= e->heigth
		&& e->move == 1)
	{
		e->diff_fractx = (double)x / ((double)e->width / (e->x2 - e->x1)) +
			e->x1;
		e->diff_fracty = (double)y / ((double)e->heigth / (e->y2 - e->y1)) +
			e->y1;
	}
	return (0);
}
