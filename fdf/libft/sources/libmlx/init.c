/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:17:39 by malexand          #+#    #+#             */
/*   Updated: 2016/12/07 12:44:24 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libmlx.h"
#include "../../includes/libft.h"

t_point		*new_point(int x, int y, char *z, int color)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(*point))))
		error(1, 0, "Malloc struct point");
	point->px = 0;
	point->py = 0;
	point->x = x;
	point->y = y;
	point->z = ft_atoi(z);
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
	mlx->prof = 2;
	mlx->decaly = 0;
	mlx->decalx = 0;
	mlx->width = w;
	mlx->heigth = h;
	mlx->persp = 2;
	mlx->diff = 1;
	mlx->diag = 0;
	mlx->color = 4;
	mlx->point = NULL;
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
