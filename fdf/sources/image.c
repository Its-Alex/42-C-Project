/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:00:00 by malexand          #+#    #+#             */
/*   Updated: 2016/12/14 14:40:52 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
			mlx->point[line][column]->px = 400 + mlx->decalx + 0.81 *
				(mlx->point[line][column]->y - mlx->point[line][column]->x)
					* mlx->zoom;
			mlx->point[line][column]->py = 150 + mlx->decaly + 0.41 *
				(mlx->point[line][column]->y + mlx->point[line][column]->x)
					* mlx->zoom - 0.41 * mlx->point[line][column]->z *
						mlx->prof;
			column++;
		}
		line++;
	}
}

static	void		trace_diag(t_mlx *mlx)
{
	int		line;
	int		column;

	line = 0;
	while (mlx->point[line])
	{
		column = 0;
		while (mlx->point[line][column])
		{
			if (mlx->point[line + 1])
				if (mlx->point[line + 1][column + 1])
					mlx_put_line(mlx, mlx->point[line][column],
						mlx->point[line + 1][column + 1]);
			if (line >= 1)
				if (mlx->point[line - 1][column + 1])
					mlx_put_line(mlx, mlx->point[line][column],
						mlx->point[line - 1][column + 1]);
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
			if (mlx->point[line + 1])
				mlx_put_line(mlx, mlx->point[line][column],
					mlx->point[line + 1][column]);
			if (mlx->point[line][column + 1])
				mlx_put_line(mlx, mlx->point[line][column],
					mlx->point[line][column + 1]);
			if (!mlx->point[line + 1] && !mlx->point[line][column + 1])
			{
				mlx_put_line(mlx, mlx->point[line][column],
					mlx->point[line][column]);
			}
			column++;
		}
		line++;
	}
}

int					put_img(t_mlx *mlx)
{
	point_init_iso(mlx);
	point_put_img(mlx);
	if (mlx->diag == 1)
		trace_diag(mlx);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	put_menu(mlx);
	return (0);
}
