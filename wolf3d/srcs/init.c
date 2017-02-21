/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:23:37 by malexand          #+#    #+#             */
/*   Updated: 2017/02/21 16:59:28 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static t_persp		*init_persp2(t_persp *p)
{
	p->sidedistx = 0.0;
	p->sidedisty = 0.0;
	p->deltadistx = 0.0;
	p->deltadisty = 0.0;
	p->perpwalldist = 0.0;
	p->stepx = 0;
	p->stepy = 0;
	p->side = 0;
	p->lineheight = 0;
	p->drawstart = 0;
	p->drawend = 0;
	p->hit = 0;
	p->mapx = 0;
	p->mapy = 0;
	return (p);
}

static t_persp		*init_persp(void)
{
	t_persp		*p;

	if ((p = (t_persp *)malloc(sizeof(t_persp))) == NULL)
		error(1, 0, "Malloc struct pective!");
	p->posx = 0.0;
	p->posy = 0.0;
	p->dirx = -1.0;
	p->diry = 0.0;
	p->planex = 0.0;
	p->planey = 0.60;
	p->camerax = 0.0;
	p->xraypos = 0.0;
	p->yraypos = 0.0;
	p->xraydir = 0.0;
	p->yraydir = 0.0;
	p->sidedistx = 0.0;
	p->sidedisty = 0.0;
	p->deltadistx = 0.0;
	p->deltadisty = 0.0;
	p->perpwalldist = 0.0;
	p = init_persp2(p);
	return (p);
}

t_map				*init_map(t_env *e, char *filename)
{
	t_map		*map;

	(void)e;
	if ((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		error(1, 0, "Malloc map!");
	if (filename == NULL)
	{
		map->column = 25;
		map->line = 25;
		map->mapget = NULL;
		get_randmap(&map);
		gen_spawn(e, map);
	}
	else
	{
		map->mapget = get_map(&map, filename);
		atoi_map(&map);
		get_spawn(e, map);
	}
	return (map);
}

t_env				*init_env(char *filename)
{
	t_env		*e;

	if ((e = (t_env *)malloc(sizeof(t_env))) == NULL)
		error(1, 0, "Malloc struct environment!");
	e->persp = init_persp();
	if (filename != NULL)
		e->filename = ft_strdup(filename);
	else
		e->filename = NULL;
	e->map = init_map(e, filename);
	e->width = 512 * 3;
	e->height = 384 * 3;
	e->mlx = mlx_init();
	e->view = init_img(e, e->width, e->height);
	e->mmap = init_img(e, e->map->column * 4, e->map->line * 4);
	e->wall = init_texture(e, "greystone.xpm");
	e->door = init_texture(e, "greystone_door.xpm");
	e->sky = init_texture(e, "sky.xpm");
	e->win = mlx_new_window(e->mlx, e->width, e->height, "Wolf3D");
	e->init = 0;
	e->key.run = 0;
	e->key.turn = 0;
	return (e);
}
