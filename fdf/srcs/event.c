/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:41:23 by malexand          #+#    #+#             */
/*   Updated: 2017/04/28 14:49:08 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				press_destroy(t_mlx *mlx)
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
			free(mlx->point[line][column]);
			column++;
		}
		free(mlx->point[line]);
		line++;
	}
	free(mlx->point);
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx->img);
	free(mlx->mlx);
	free(mlx);
	exit(0);
	return (0);
}

int				key_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		press_destroy(mlx);
	if (keycode == KEY_1)
		mlx->t_prof = 1;
	if (keycode == KEY_2)
		mlx->t_prof = -1;
	if (keycode == KEY_LEFT)
		mlx->t_decalx = -1;
	if (keycode == KEY_RIGTH)
		mlx->t_decalx = 1;
	if (keycode == KEY_UP)
		mlx->t_decaly = -1;
	if (keycode == KEY_DOWN)
		mlx->t_decaly = 1;
	if (keycode == KEY_MOIN)
		mlx->t_zoom = 1;
	if (keycode == KEY_PLUS)
		mlx->t_zoom = -1;
	if (keycode == KEY_D)
		mlx->diag = (mlx->diag == 0) ? 1 : 0;
	if (keycode == KEY_C && mlx->color < 20000000)
		mlx->color++;
	mlx = (keycode == KEY_R) ? reset_mlx(mlx) : mlx;
	return (0);
}

int				key_release(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_1)
		mlx->t_prof = 0;
	if (keycode == KEY_2)
		mlx->t_prof = 0;
	if (keycode == KEY_LEFT)
		mlx->t_decalx = 0;
	if (keycode == KEY_RIGTH)
		mlx->t_decalx = 0;
	if (keycode == KEY_UP)
		mlx->t_decaly = 0;
	if (keycode == KEY_DOWN)
		mlx->t_decaly = 0;
	if (keycode == KEY_PLUS)
		mlx->t_zoom = 0;
	if (keycode == KEY_MOIN)
		mlx->t_zoom = 0;
	return (0);
}

int				loop(t_mlx *mlx)
{
	if (mlx->t_prof == 1 && mlx->prof < INT_MAX)
		mlx->prof += 2;
	if (mlx->t_prof == -1 && mlx->prof > INT_MIN)
		mlx->prof += -2;
	if (mlx->t_zoom == 1 && mlx->zoom < 20000000.0)
		mlx->zoom += 0.25;
	if (mlx->t_zoom == -1 && mlx->zoom > 0)
		mlx->zoom += -0.25;
	if (mlx->t_decalx == 1 && mlx->decalx < INT_MAX)
		mlx->decalx += 10;
	if (mlx->t_decalx == -1 && mlx->decalx > INT_MIN)
		mlx->decalx += -10;
	if (mlx->t_decaly == 1 && mlx->decaly < INT_MAX)
		mlx->decaly += 10;
	if (mlx->t_decaly == -1 && mlx->decaly > INT_MIN)
		mlx->decaly += -10;
	ft_bzero(mlx->img->addr, mlx->heigth * mlx->img->size_l);
	put_img(mlx);
	return (0);
}
