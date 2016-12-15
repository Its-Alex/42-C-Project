/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:01:06 by malexand          #+#    #+#             */
/*   Updated: 2016/12/15 11:14:48 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point		*new_point(int x, int y, char *z, int color)
{
	t_point	*point;
	long	test;

	test = ft_atoi(z);
	if (!(point = (t_point *)malloc(sizeof(*point))))
		error(1, 0, "Malloc struct point");
	point->px = 0;
	point->py = 0;
	point->x = x;
	point->y = y;
	if (test >= 0 && test <= 2147480000)
		point->z = test;
	else
		point->z = 0;
	point->color = color;
	return (point);
}

t_mlx		*init_mlx(t_mlx *mlx, int w, int h)
{
	if ((mlx = (t_mlx *)malloc(sizeof(t_mlx))) == NULL)
		error(1, 0, "Malloc struct mlx");
	mlx->mlx = mlx_init();
	if (w < 250 || h < 250 || w > 2550 ||
		h > 1080)
	{
		w = 1000;
		h = 1000;
	}
	mlx->win = mlx_new_window(mlx->mlx, w, h, "fdf");
	mlx->decaly = 0;
	mlx->decalx = 0;
	mlx->zoom = 30.0;
	mlx->prof = 2;
	mlx->width = w;
	mlx->heigth = h;
	mlx->diag = 0;
	mlx->point = NULL;
	mlx->t_decalx = 0;
	mlx->t_decaly = 0;
	mlx->t_zoom = 0;
	mlx->t_prof = 0;
	mlx->t_decalx = 0;
	mlx->t_decaly = 0;
	return (mlx);
}

t_img		*init_img(t_mlx *mlx)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(*img))))
		error(1, 0, "Malloc struct img");
	img->img = mlx_new_image(mlx->mlx, mlx->width, mlx->heigth);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_l),
		&(img->endian));
	return (img);
}
