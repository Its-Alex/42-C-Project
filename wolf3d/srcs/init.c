/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:23:37 by malexand          #+#    #+#             */
/*   Updated: 2017/02/03 17:57:36 by malexand         ###   ########.fr       */
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
	p->posx = 2.5;
	p->posy = 2.5;
	p->dirx = 1.0;
	p->diry = 0.0;
	p->planex = 0.0;
	p->planey = 0.60;
	p->camerax = 0.0;
	p->rayposx = 0.0;
	p->rayposy = 0.0;
	p->raydirx = 0.0;
	p->raydiry = 0.0;
	p->sidedistx = 0.0;
	p->sidedisty = 0.0;
	p->deltadistx = 0.0;
	p->deltadisty = 0.0;
	p->perpwalldist = 0.0;
	p = init_persp2(p);
	return (p);
}

static t_map		*init_map(char *filename)
{
	t_map		*map;

	if ((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		error(1, 0, "Malloc map!");
	map->x = 25;
	map->y = 25;
	if (filename == NULL)
	{
		map->mapget = NULL;
		get_randmap(&map, 25, 25);
	}
	else
	{
		map->mapget = get_map(&map, filename);
		atoi_map(&map, map->x, map->y);
	}
	return (map);
}

static t_img		*init_img(t_env *e, int width, int heigth)
{
	t_img		*img;

	if ((img = (t_img *)malloc(sizeof(t_img))) == NULL)
		error(1, 0, "Malloc struct img!");
	img->img = mlx_new_image(e->mlx, width, heigth);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_l),
		&(img->endian));
	img->x = width;
	img->y = heigth;
	img->trans = 0;
	return (img);
}

t_env				*init_env(char *filename)
{
	t_env		*e;

	if ((e = (t_env *)malloc(sizeof(t_env))) == NULL)
		error(1, 0, "Malloc struct environment!");
	e->persp = init_persp();
	e->map = init_map(filename);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGTH, "Wolf3D");
	e->view = init_img(e, WIDTH, HEIGTH);
	e->mmap = init_img(e, e->map->x * 6, e->map->y * 6);
	e->mmap->trans = 65;
	e->init = 0;
	return (e);
}
