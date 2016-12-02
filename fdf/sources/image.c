/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:00:00 by malexand          #+#    #+#             */
/*   Updated: 2016/12/02 17:56:26 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
			if (mlx->point[line + 1])
				mlx_put_line(mlx, mlx->point[line][column],
					mlx->point[line + 1][column]);
			if (mlx->point[line][column + 1])
				mlx_put_line(mlx, mlx->point[line][column],
					mlx->point[line][column + 1]);
			column++;
		}
		line++;
	}
}

static	void		point_init_iso(t_mlx *mlx)
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
			mlx->point[line][column]->px = 500 + ((double)mlx->point[line][column]->x * (cos(mlx->cosinus) * 15)) - ((double)mlx->point[line][column]->y * (sin(mlx->sinus) * 15));
			mlx->point[line][column]->py = 500 + ((double)mlx->point[line][column]->x * (sin(mlx->sinus) * 15)) + ((double)mlx->point[line][column]->y * (cos(mlx->cosinus) * 15)) + mlx->point[line][column]->z;
			printf("%d, %d\n", mlx->point[line][column]->px, mlx->point[line][column]->py);
			column++;
		}
		line++;
	}
}

int					put_img(t_mlx *mlx)
{
	mlx->img = init_img(mlx);
	point_init_iso(mlx);
	point_put_img(mlx);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	return (0);
}
