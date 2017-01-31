/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:23:37 by malexand          #+#    #+#             */
/*   Updated: 2017/01/31 15:24:04 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_img			*init_img(t_env *e)
{
	t_img	*img;

	if ((img = (t_img *)malloc(sizeof(t_img))) == NULL)
		error(1, 0, "Malloc struct img");
	img->img = mlx_new_image(e->mlx, e->w, e->h);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_l),
		&(img->endian));
	return (img);
}

t_env			*init_env(int w, int h)
{
	t_env	*e;

	if ((e = (t_env *)malloc(sizeof(t_env))) == NULL)
		error(1, 0, "Malloc environment");
	e->w = (w >= 300 && w <= 2559) ? w : 1000;
	e->h = (h >= 300 && h <= 1439) ? h : 640;
	e->map = get_map(e, "maps/base");
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->w, e->h, "Wolf3D");
	e->img = init_img(e);
	e->init = 0;
	return (e);
}
