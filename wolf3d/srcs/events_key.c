/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:05:55 by malexand          #+#    #+#             */
/*   Updated: 2017/02/02 16:46:04 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		key_params(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		press_destroy(e);
}

int				key_press(int keycode, t_env *e)
{
	double		tmp;

	key_params(keycode, e);
	if (keycode == KEY_UP)
	{
		if (e->map->mapgen[(int)(e->persp->posx + e->persp->dirx * 0.5)][(int)(e->persp->posy)] == 0)
			e->persp->posx += e->persp->dirx * 0.5;
		if (e->map->mapgen[(int)(e->persp->posx)][(int)(e->persp->posy + e->persp->diry * 0.5)] == 0)
			e->persp->posx += e->persp->dirx * 0.5;
	}
	if (keycode == KEY_DOWN)
	{
		if (e->map->mapgen[(int)(e->persp->posx - e->persp->dirx * 0.5)][(int)(e->persp->posy)] == 0)
			e->persp->posx -= e->persp->dirx * 0.5;
		if (e->map->mapgen[(int)(e->persp->posx)][(int)(e->persp->posy - e->persp->diry * 0.5)] == 0)
			e->persp->posx -= e->persp->dirx * 0.5;
	}
	if (keycode == KEY_RIGTH)
	{
		tmp = e->persp->dirx;
		e->persp->dirx = e->persp->dirx * cos(-0.2) - e->persp->diry * sin(-0.2);
		e->persp->diry = tmp * sin(-0.2) + e->persp->diry * cos(-0.2);
		tmp = e->persp->planex;
		e->persp->planex = e->persp->planex * cos(-0.2) - e->persp->planey * sin(-0.2);
    	e->persp->planey = tmp * sin(-0.2) + e->persp->planey * cos(-0.2);
	}
	if (keycode == KEY_LEFT)
	{
		tmp = e->persp->dirx;
		e->persp->dirx = e->persp->dirx * cos(0.2) - e->persp->diry * sin(0.2);
		e->persp->diry = tmp * sin(0.2) + e->persp->diry * cos(0.2);
		tmp = e->persp->planex;
		e->persp->planex = e->persp->planex * cos(0.2) - e->persp->planey * sin(0.2);
    	e->persp->planey = tmp * sin(0.2) + e->persp->planey * cos(0.2);
	}
	return (0);
}

int				key_release(int keycode, t_env *e)
{
	key_params(keycode, e);
	return (0);
}
