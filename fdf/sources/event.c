/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:41:23 by malexand          #+#    #+#             */
/*   Updated: 2016/12/14 14:58:37 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	gere_key(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		press_destroy(mlx);
	mlx->zoom = (keycode == KEY_PLUS) ? mlx->zoom : mlx->zoom + 0.25;
	if (mlx->zoom > 0)
		mlx->zoom = (keycode == KEY_MOIN) ? mlx->zoom : mlx->zoom - 0.25;
	mlx->prof = (keycode == KEY_1) ? mlx->prof : mlx->prof + 2;
	mlx->prof = (keycode == KEY_2) ? mlx->prof : mlx->prof - 2;
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
	ft_putstr("Key event : ");
	ft_putnbr(keycode);
	ft_putendl("");
	return (0);
}

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
	exit(0);
	return (0);
}
