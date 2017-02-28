/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:00:19 by malexand          #+#    #+#             */
/*   Updated: 2017/02/28 17:38:08 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		init(t_env *e, int x)
{
	e->persp->xraypos = e->persp->posx;
	e->persp->yraypos = e->persp->posy;
	e->persp->mapx = (int)e->persp->xraypos;
	e->persp->mapy = (int)e->persp->yraypos;
	e->persp->camerax = 2 * x / (double)e->width - 1;
	e->persp->xraydir = e->persp->dirx + e->persp->planex * e->persp->camerax;
	e->persp->yraydir = e->persp->diry + e->persp->planey * e->persp->camerax;
	e->persp->deltadistx = sqrt(1 + (e->persp->yraydir * e->persp->yraydir) /
		(e->persp->xraydir * e->persp->xraydir));
	e->persp->deltadisty = sqrt(1 + (e->persp->xraydir * e->persp->xraydir) /
		(e->persp->yraydir * e->persp->yraydir));
	e->persp->hit = 0;
}

static void		check_dir(t_env *e)
{
	if (e->persp->xraydir < 0)
	{
		e->persp->stepx = -1;
		e->persp->sidedistx = (e->persp->xraypos -
			(int)e->persp->mapx) * e->persp->deltadistx;
	}
	else
	{
		e->persp->stepx = 1;
		e->persp->sidedistx = ((int)e->persp->mapx + 1 -
			e->persp->xraypos) * e->persp->deltadistx;
	}
	if (e->persp->yraydir < 0)
	{
		e->persp->stepy = -1;
		e->persp->sidedisty = (e->persp->yraypos -
			(int)e->persp->mapy) * e->persp->deltadisty;
	}
	else
	{
		e->persp->stepy = 1;
		e->persp->sidedisty = ((int)e->persp->mapy + 1 -
			e->persp->yraypos) * e->persp->deltadisty;
	}
}

static void		find_wall(t_env *e)
{
	while (e->persp->hit == 0)
	{
		if (e->persp->sidedistx < e->persp->sidedisty)
		{
			e->persp->sidedistx += e->persp->deltadistx;
			e->persp->mapx += e->persp->stepx;
			e->persp->side = 0;
		}
		else
		{
			e->persp->sidedisty += e->persp->deltadisty;
			e->persp->mapy += e->persp->stepy;
			e->persp->side = 1;
		}
		if (e->map->mapgen[e->persp->mapx][e->persp->mapy] != 0 &&
				e->map->mapgen[e->persp->mapx][e->persp->mapy] != 42)
			e->persp->hit = 1;
		else
		{
			mmap_ray(e, e->persp->mapx, e->persp->mapy);
		}
	}
}

static int		calc_draw(t_env *e)
{
	double	wallx;
	int		xtexture;

	if (e->persp->side == 0)
		e->persp->perpwalldist = (e->persp->mapx - e->persp->xraypos +
			(1 - e->persp->stepx) / 2) / e->persp->xraydir;
	else
		e->persp->perpwalldist = (e->persp->mapy - e->persp->yraypos +
			(1 - e->persp->stepy) / 2) / e->persp->yraydir;
	e->persp->lineheight = (int)(e->height / e->persp->perpwalldist);
	e->persp->drawstart = -e->persp->lineheight / 2 + e->height / 2;
	e->persp->drawend = e->persp->lineheight / 2 + e->height / 2;
	if (e->persp->side == 0)
		wallx = e->persp->yraypos + e->persp->perpwalldist
			* e->persp->yraydir;
	else
		wallx = e->persp->xraypos + e->persp->perpwalldist
			* e->persp->xraydir;
	wallx -= floor(wallx);
	xtexture = (int)(wallx * (double)(64));
	if (e->persp->xraydir != 0)
		xtexture = 64 - xtexture - 1;
	return (xtexture);
}

void			ray_casting(t_env *e)
{
	int			x;
	t_draw		draw;

	x = 0;
	while (x < e->width)
	{
		init(e, x);
		check_dir(e);
		find_wall(e);
		draw.x = x;
		draw.x_tex = calc_draw(e);
		draw.start = e->persp->drawstart;
		draw.stop = e->persp->drawend;
		draw_line(e, draw);
		x++;
	}
}
