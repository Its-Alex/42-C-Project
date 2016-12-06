/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:41:23 by malexand          #+#    #+#             */
/*   Updated: 2016/12/06 17:53:05 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		free_func(t_mlx *mlx)
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
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx->mlx);
	free(mlx);
	exit(0);
}

static	t_mlx	*reset_mlx(t_mlx *mlx)
{
	mlx->prof = 10;
	mlx->decaly = 0;
	mlx->decalx = 0;
	mlx->persp = 10;
	mlx->diff = 1;
	mlx->diag = 0;
	mlx->color = 4;
	return (mlx);
}

static	void	gere_key(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		free_func(mlx);
	mlx->persp = (keycode == KEY_1) ? mlx->persp : mlx->persp + 1;
	mlx->persp = (keycode == KEY_2) ? mlx->persp : mlx->persp - 1;
	mlx->prof = (keycode == KEY_3) ? mlx->prof : mlx->prof + 1;
	mlx->prof = (keycode == KEY_4) ? mlx->prof : mlx->prof - 1;
	mlx->diff = (keycode == KEY_5) ? mlx->diff : mlx->diff + 1;
	mlx->diff = (keycode == KEY_6) ? mlx->diff : mlx->diff - 1;
	mlx->decalx = (keycode == KEY_LEFT) ? mlx->decalx : mlx->decalx + 10;
	mlx->decalx = (keycode == KEY_RIGHT) ? mlx->decalx : mlx->decalx - 10;
	mlx->decaly = (keycode == KEY_UP) ? mlx->decaly : mlx->decaly + 10;
	mlx->decaly = (keycode == KEY_DOWN) ? mlx->decaly : mlx->decaly - 10;
	if (keycode == KEY_D)
		mlx->diag = (mlx->diag == 0) ? 1 : 0;
	if (keycode == KEY_C)
		mlx->color++;
	if (mlx->color == 5)
		mlx->color = 1;
	mlx = (keycode == KEY_R) ? reset_mlx(mlx) : mlx;
}

int				my_keyfunc(int keycode, t_mlx *mlx)
{
	gere_key(keycode, mlx);
	ft_bzero(mlx->img->addr, mlx->heigth * mlx->img->size_l +
		mlx->width * mlx->img->bpp / 8 + 2);
	mlx_clear_window(mlx->mlx, mlx->win);
	put_img(mlx);
	printf("Key event : %d\n", keycode);
	return (0);
}

int				pressDestroy(t_mlx *mlx)
{
	free_func(mlx);
	return (0);
}
