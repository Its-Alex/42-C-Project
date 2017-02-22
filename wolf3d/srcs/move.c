/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:28:29 by malexand          #+#    #+#             */
/*   Updated: 2017/02/22 11:41:05 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		run_forward(t_env *e, double speed)
{
	if (e->key.run == 1)
	{
		if (e->map->mapgen[(int)(e->persp->posx + e->persp->dirx * speed * 4)]
				[(int)(e->persp->posy)] != 1)
			if (e->map->mapgen[(int)(e->persp->posx + e->persp->dirx * speed
				* 4)][(int)(e->persp->posy)] != 2)
				if (e->map->mapgen[(int)(e->persp->posx +
						e->persp->dirx * speed * 4)]
						[(int)(e->persp->posy)] != 4)
					e->persp->posx += e->persp->dirx * speed;
		if (e->map->mapgen[(int)(e->persp->posx)]
				[(int)(e->persp->posy + e->persp->diry * speed * 4)] != 1)
			if (e->map->mapgen[(int)(e->persp->posx)]
					[(int)(e->persp->posy + e->persp->diry * speed * 4)] != 2)
				if (e->map->mapgen[(int)(e->persp->posx)
					][(int)(e->persp->posy + e->persp->diry * speed * 4)] != 4)
					e->persp->posy += e->persp->diry * speed;
	}
}

static void		run_backward(t_env *e, double speed)
{
	if (e->key.run == -1)
	{
		if (e->map->mapgen[(int)(e->persp->posx - e->persp->dirx * speed * 4)]
				[(int)(e->persp->posy)] != 1)
			if (e->map->mapgen[(int)(e->persp->posx - e->persp->dirx * speed
				* 4)][(int)(e->persp->posy)] != 2)
				if (e->map->mapgen[(int)(e->persp->posx -
						e->persp->dirx * speed * 4)]
						[(int)(e->persp->posy)] != 4)
					e->persp->posx -= e->persp->dirx * speed;
		if (e->map->mapgen[(int)(e->persp->posx)]
				[(int)(e->persp->posy - e->persp->diry * speed * 4)] != 1)
			if (e->map->mapgen[(int)(e->persp->posx)]
					[(int)(e->persp->posy - e->persp->diry * speed * 4)] != 2)
				if (e->map->mapgen[(int)(e->persp->posx)
					][(int)(e->persp->posy - e->persp->diry * speed * 4)] != 4)
					e->persp->posy -= e->persp->diry * speed;
	}
}

static void		turn(t_env *e, double speed)
{
	if (e->key.turn == 1)
	{
		rotate(&(e->persp->dirx), &(e->persp->diry), speed);
		rotate(&(e->persp->planex), &(e->persp->planey), speed);
	}
	if (e->key.turn == -1)
	{
		rotate(&(e->persp->dirx), &(e->persp->diry), -speed);
		rotate(&(e->persp->planex), &(e->persp->planey), -speed);
	}
}

static void		strafe(t_env *e, double speed)
{
	(void)e;
	(void)speed;
}

void			key_move(t_env *e, double speed)
{
	run_forward(e, speed);
	run_backward(e, speed);
	check_floor(e);
	turn(e, speed);
	strafe(e, speed);
}
