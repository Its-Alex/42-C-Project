/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:20:05 by malexand          #+#    #+#             */
/*   Updated: 2016/12/16 12:40:21 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_img			*init_img(t_env *e)
{
	t_img	*img;

	if ((img = (t_img *)malloc(sizeof(t_img))) == NULL)
		error(1, 0, "Malloc struct img");
	img->img = mlx_new_image(e->mlx, e->width, e->heigth);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_l),
		&(img->endian));
	return (img);
}

t_env			*init_env(int width, int heigth)
{
	t_env	*e;

	if ((e = (t_env *)malloc(sizeof(t_env))) == NULL)
		error(1, 0, "Malloc struct e");
	e->width = (width >= 250 && width <= 2550) ? width : 1000;
	e->heigth = (heigth >= 250 && heigth <= 1080) ? heigth : 1000;
	e->mlx = mlx_init();
	e->win = NULL;
	e->img = init_img(e);
	e->dx = 0;
	e->dy = 0;
	e->t_dx = 0;
	e->t_dy = 0;
	e->zoom = 1.0;
	e->t_zoom = 0;
	e->reload = 0;
	e->color = 0xFFFFFF;
	return (e);
}
