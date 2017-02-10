/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:28:29 by malexand          #+#    #+#             */
/*   Updated: 2017/02/10 15:53:21 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		run(t_env *e)
{
	double		speed;

	speed = 0.04;
	if (e->key.run == 1)
	{
		if(e->map->mapgen[(int)(e->persp->posx + e->persp->dirx * speed)]
				[(int)(e->persp->posy)] != 1)
			e->persp->posx += e->persp->dirx * speed;
    	if(e->map->mapgen[(int)(e->persp->posx)]
    			[(int)(e->persp->posy + e->persp->diry * speed)] != 1)
    		e->persp->posy += e->persp->diry * speed;

	}
	if (e->key.run == -1)
	{
		if(e->map->mapgen[(int)(e->persp->posx - e->persp->dirx * speed)]
				[(int)(e->persp->posy)] != 1)
			e->persp->posx -= e->persp->dirx * speed;
    	if(e->map->mapgen[(int)(e->persp->posx)]
    			[(int)(e->persp->posy - e->persp->diry * speed)] != 1)
    		e->persp->posy -= e->persp->diry * speed;
	}
}

void	key_move(t_env *e)
{
	run(e);
	if (e->key.turn == 1)
	{
		rotate(&(e->persp->dirx), &(e->persp->diry), 0.04);
		rotate(&(e->persp->planex), &(e->persp->planey), 0.04);
	}
	if (e->key.turn == -1)
	{
		rotate(&(e->persp->dirx), &(e->persp->diry), -0.04);
		rotate(&(e->persp->planex), &(e->persp->planey), -0.04);
	}
}