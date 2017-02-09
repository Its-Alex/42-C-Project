/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:00:19 by malexand          #+#    #+#             */
/*   Updated: 2017/02/09 15:42:32 by malexand         ###   ########.fr       */
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
	int		x;
	int		color;

	x = 0;
	color = 0xFFFFFF;
	while (x < e->width)
	{
		e->persp->camerax = 2 * x / (double)(e->width - 1);
		e->persp->rayposx = e->persp->posx;
		e->persp->rayposy = e->persp->posy;
		e->persp->raydirx = e->persp->dirx + e->persp->planex * e->persp->camerax;
		e->persp->raydiry = e->persp->diry + e->persp->planey * e->persp->camerax;
		e->persp->mapx = (int)(e->persp->rayposx);
		e->persp->mapy = (int)(e->persp->rayposy);

		e->persp->deltadistx = sqrt(1 + (e->persp->raydiry * e->persp->raydiry) / (e->persp->raydirx * e->persp->raydirx));
		e->persp->deltadisty = sqrt(1 + (e->persp->raydirx * e->persp->raydirx) / (e->persp->raydiry * e->persp->raydiry));

		e->persp->hit = 0;

		if (e->persp->raydirx < 0)
		{
			e->persp->stepx = -1;
			e->persp->sidedistx = (e->persp->rayposx - e->persp->mapx) * e->persp->deltadistx;
		}
		else
		{
			e->persp->stepx = 1;
			e->persp->sidedistx = (e->persp->mapx + 1.0 - e->persp->rayposx) * e->persp->deltadistx;
		}
		if (e->persp->raydiry < 0)
		{
			e->persp->stepy = -1;
			e->persp->sidedisty = (e->persp->rayposy - e->persp->mapy) * e->persp->deltadisty;
		}
		else
		{
			e->persp->stepy = 1;
			e->persp->sidedisty = (e->persp->mapy + 1.0 - e->persp->rayposy) * e->persp->deltadisty;
		}

		while (e->persp->hit == 0)
		{
			if (e->persp->sidedistx < e->persp->sidedisty)
	        {
	          e->persp->sidedistx += e->persp->deltadistx;
	          e->persp->mapx += e->persp->stepx;
	          e->persp->side = 0;
	          if (e->persp->stepx == 1)
	          	color = 0xFF0000;
	          else
	          	color = 0x0000FF;
	        }
	        else
	        {
	          e->persp->sidedisty += e->persp->deltadisty;
	          e->persp->mapy += e->persp->stepy;
	          e->persp->side = 1;
	          if (e->persp->stepy == 1)
	          	color = 0x00FFFF;
	          else
	          	color = 0xFF00FF;
	        }
	        //Check if ray has hit a wall
	        if (e->map->mapgen[e->persp->mapx][e->persp->mapy] == 1)
	        	e->persp->hit = 1;
		}

		if (e->persp->side == 0)
			e->persp->perpwalldist = (e->persp->mapx - e->persp->rayposx + (1 - e->persp->stepx) / 2) / e->persp->raydirx;
		else
			e->persp->perpwalldist = (e->persp->mapy - e->persp->rayposy + (1 - e->persp->stepy) / 2) / e->persp->raydiry;

		e->persp->lineheight = (int)(e->heigth / e->persp->perpwalldist);

		e->persp->drawstart = -e->persp->lineheight / 2 + e->heigth / 2;
		if (e->persp->drawstart < 0)
			e->persp->drawstart = 0;
		e->persp->drawend = e->persp->lineheight / 2 + e->heigth / 2;
		if (e->persp->drawend < 0)
			e->persp->drawend = e->heigth - 1;

		draw_line(e, x, e->persp->drawstart, e->persp->drawend, color);
		x++;
	}
}
