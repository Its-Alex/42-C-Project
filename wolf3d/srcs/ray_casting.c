/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:00:19 by malexand          #+#    #+#             */
/*   Updated: 2017/02/10 16:26:27 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		init(t_env *e, int x)
{
	e->persp->camerax = 2 * x / (double)(e->width - 1);
	e->persp->rayposx = e->persp->posx;
	e->persp->rayposy = e->persp->posy;
	e->persp->raydirx = e->persp->dirx + e->persp->planex * e->persp->camerax;
	e->persp->raydiry = e->persp->diry + e->persp->planey * e->persp->camerax;
	rotate(&(e->persp->raydirx), &(e->persp->raydiry), 0.5);
	e->persp->mapx = (int)(e->persp->rayposx);
	e->persp->mapy = (int)(e->persp->rayposy);
	e->persp->deltadistx = sqrt(1 + (e->persp->raydiry * e->persp->raydiry) /
		(e->persp->raydirx * e->persp->raydirx));
	e->persp->deltadisty = sqrt(1 + (e->persp->raydirx * e->persp->raydirx) /
		(e->persp->raydiry * e->persp->raydiry));
	e->persp->hit = 0;
}

static void		check_dir(t_env *e)
{
	if (e->persp->raydirx < 0)
	{
		e->persp->stepx = -1;
		e->persp->sidedistx = (e->persp->rayposx - e->persp->mapx)
		* e->persp->deltadistx;
	}
	else
	{
		e->persp->stepx = 1;
		e->persp->sidedistx = (e->persp->mapx + 1.0 - e->persp->rayposx)
		* e->persp->deltadistx;
	}
	if (e->persp->raydiry < 0)
	{
		e->persp->stepy = -1;
		e->persp->sidedisty = (e->persp->rayposy - e->persp->mapy)
		* e->persp->deltadisty;
	}
	else
	{
		e->persp->stepy = 1;
		e->persp->sidedisty = (e->persp->mapy + 1.0 - e->persp->rayposy)
		* e->persp->deltadisty;
	}
}

static void		find_wall(t_env *e, int *color)
{
	while (e->persp->hit == 0)
	{
		if (e->persp->sidedistx < e->persp->sidedisty)
		{
			e->persp->sidedistx += e->persp->deltadistx;
			e->persp->mapx += e->persp->stepx;
			e->persp->side = 0;
			if (e->persp->stepx == 1)
				*color = RGB(190, 190, 190);
			else
				*color = RGB(170, 170, 170);
		}
		else
		{
			e->persp->sidedisty += e->persp->deltadisty;
			e->persp->mapy += e->persp->stepy;
			e->persp->side = 1;
			if (e->persp->stepy == 1)
				*color = RGB(150, 150, 150);
			else
				*color = RGB(210, 210, 210);
		}
		if (e->map->mapgen[e->persp->mapx][e->persp->mapy] == 1)
			e->persp->hit = 1;
		else
		{
			mmap_ray(e, e->persp->mapx, e->persp->mapy);
		}
	}
}

static void		calc_draw(t_env *e)
{
	if (e->persp->side == 0)
		e->persp->perpwalldist = (e->persp->mapx - e->persp->rayposx +
			(1 - e->persp->stepx) / 2) / e->persp->raydirx;
	else
		e->persp->perpwalldist = (e->persp->mapy - e->persp->rayposy +
			(1 - e->persp->stepy) / 2) / e->persp->raydiry;
	e->persp->lineheight = (int)(e->heigth / e->persp->perpwalldist);
	e->persp->drawstart = -e->persp->lineheight / 2 + e->heigth / 2;
	if (e->persp->drawstart < 0)
		e->persp->drawstart = 0;
	e->persp->drawend = e->persp->lineheight / 2 + e->heigth / 2;
	if (e->persp->drawend < 0)
		e->persp->drawend = e->heigth - 1;
}

void			ray_casting(t_env *e)
{
	int		x;
	int		color;

	x = 0;
	color = 0xFFFFFF;
	while (x < e->width)
	{
		init(e, x);
		check_dir(e);
		find_wall(e, &color);
		calc_draw(e);
		draw_line(e, x, e->persp->drawstart, e->persp->drawend, color);
		x++;
	}
}
