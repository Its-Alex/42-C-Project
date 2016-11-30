/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:17:39 by malexand          #+#    #+#             */
/*   Updated: 2016/11/30 18:05:58 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libmlx.h"
#include "../../includes/libft.h"

t_point		*new_point(int x, int y, char *z)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(*point))))
		error(1, 0, "Malloc struct point");
	point->x = x;
	point->y = y;
	point->z = ft_atoi(z);
	// point->color = find_color(z);
	free(z);
	return (point);
}

t_mlx		*init_mlx(t_mlx *mlx, int w, int h)
{
	if ((mlx = (t_mlx *)malloc(sizeof(t_mlx))) == NULL)
		error(1, 0, "Malloc struct mlx");
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 500, 500, "fdf");
	mlx->width = w;
	mlx->heigth = h;
	mlx->degrad = 10;
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
