/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:00:00 by malexand          #+#    #+#             */
/*   Updated: 2016/12/01 17:49:51 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void		link_point(t_mlx *mlx)
{
	int		line;
	int		column;

	line = 0;
	column = 0;
	while (mlx->point[line])
	{
		column = 0;
		while (mlx->point[line][column])
		{
			if (mlx->point[line + 1])
				mlx_trace_line(mlx, mlx->point[line][column],
					mlx->point[line + 1][column]);
			if (mlx->point[line][column + 1])
				mlx_trace_line(mlx, mlx->point[line][column],
					mlx->point[line][column + 1]);
			column++;
		}
		line++;
	}
}

static	void		point_put_img(t_mlx *mlx)
{
	int		line;
	int		column;

	line = 0;
	column = 0;
	while (mlx->point[line])
	{
		column = 0;
		while (mlx->point[line][column])
		{
			mlx->point[line][column]->py = mlx->point[line][column]->x *
				20 + 100 - mlx->point[line][column]->z;
			mlx->point[line][column]->px = mlx->point[line][column]->y *
				20 + 100 - mlx->point[line][column]->z;
			column++;
		}
		line++;
	}
}

int					put_img(t_mlx *mlx)
{
	mlx->img = init_img(mlx);
	point_put_img(mlx);
	link_point(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	return (0);
}
