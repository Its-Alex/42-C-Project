/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:06:14 by malexand          #+#    #+#             */
/*   Updated: 2016/11/30 17:39:55 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		my_keyfunc(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx);
		exit(0);
	}
	printf("Key event : %d\n", keycode);
	return (0);
}

int		draw(t_mlx *mlx)
{
	int		count;
	t_point	p1;
	t_point	p2;

	p1.x = 50;
	p1.y = 50;
	p2.x = 200;
	p2.y = 200;
	p1.color = 0x0000FF;
	count = 0;
	mlx->img = init_img(mlx);
	mlx_trace_line(mlx, p1, p2);
	mlx_pixel_put_img(0x0000FF, mlx->img, 400, 400);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	return (0);
}

void	mlx_launch(t_mlx *mlx)
{
	mlx_expose_hook(mlx->win, draw, mlx);
	mlx_key_hook(mlx->win, my_keyfunc, mlx);
	mlx_loop(mlx->mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (argc != 2)
	{
		error(1, 0, "Wrong number of mlx!");
	}
	else
	{
		mlx->point = parse(mlx, argv);
		mlx = init_mlx(mlx, 500, 500);
		mlx_launch(mlx);
	}
	return (0);
}
