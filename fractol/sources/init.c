/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:20:05 by malexand          #+#    #+#             */
/*   Updated: 2017/01/09 18:12:41 by malexand         ###   ########.fr       */
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

static void		env_fract(t_env *e)
{
	if (ft_strcmp(e->av[1], "Mandelbrot") == 0 ||
		ft_strcmp(e->av[1], "BurningShip") == 0)
	{
		e->x1 = -2.1;
		e->x2 = 0.6;
		e->y1 = -1.2;
		e->y2 = 1.2;
	}
	else if (ft_strcmp(e->av[1], "Julia") == 0)
	{
		e->x1 = -1.0;
		e->x2 = 1.0;
		e->y1 = -1.2;
		e->y2 = 1.2;
	}
}

t_env			*init_env(int width, int heigth, char **av)
{
	t_env	*e;

	if ((e = (t_env *)malloc(sizeof(t_env))) == NULL)
		error(1, 0, "Malloc struct e");
	e->width = (width >= 250 && width <= 2550) ? width : 1000;
	e->heigth = (heigth >= 250 && heigth <= 1080) ? heigth : 1000;
	e->mlx = mlx_init();
	e->win = NULL;
	e->img = init_img(e);
	e->av = av;
	e->dx = 0;
	e->dy = 0;
	e->t_dx = 0;
	e->t_dy = 0;
	e->init = 0;
	e->t_imax = 0;
	e->imax = 15.0;
	e->t_zoom = 0;
	e->reload = 0;
	e->color = 0xFFFFFF;
	env_fract(e);
	e->zoomx = (e->width / ((e->x2 + e->dx) - (e->x1 + e->dx)));
	e->zoomy = (e->heigth / ((e->y2 + e->dy) - (e->y1 + e->dy)));
	return (e);
}
