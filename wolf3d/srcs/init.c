/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:23:37 by malexand          #+#    #+#             */
/*   Updated: 2017/02/01 16:36:30 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static t_persp		*init_persp(void)
{
	t_persp		*persp;

	if ((persp = (t_persp *)malloc(sizeof(t_persp))) == NULL)
		error(1, 0, "Malloc struct perspective!");
	persp->fov = 90.0;
	persp->posx = 0.0;
	persp->posy = 0.0;
	persp->dirx = 0.0;
	persp->diry = 0.0;
	persp->alpha = 0.0;
	persp->beta = 0.0;
	return (persp);
}

static t_map		*init_map(char *filename)
{
	t_map		*map;

	if ((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		error(1, 0, "Malloc map!");
	map->x = 50;
	map->y = 50;
	if (filename == NULL)
	{
		map->mapget = NULL;
		get_randmap(&map, 50, 50);
	}
	else
	{
		map->mapget = get_map(&map, filename);
		atoi_map(&map, 50, 50);
	}
	return (map);
}

static t_img		*init_img(t_env *e)
{
	t_img		*img;

	if ((img = (t_img *)malloc(sizeof(t_img))) == NULL)
		error(1, 0, "Malloc struct img!");
	img->img = mlx_new_image(e->mlx, e->w, e->h);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_l),
		&(img->endian));
	return (img);
}

t_env				*init_env(int w, int h, char *filename)
{
	t_env		*e;

	if ((e = (t_env *)malloc(sizeof(t_env))) == NULL)
		error(1, 0, "Malloc struct environment!");
	e->w = (w >= 300 && w <= 2559) ? w : 360 * 4;
	e->h = (h >= 300 && h <= 1439) ? h : 200 * 4;
	e->persp = init_persp();
	e->map = init_map(filename);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->w, e->h, "Wolf3D");
	e->img = init_img(e);
	e->init = 0;
	return (e);
}
