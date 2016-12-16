/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:05:55 by malexand          #+#    #+#             */
/*   Updated: 2016/12/16 13:00:14 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				press_destroy(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img->img);
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_window(e->mlx, e->win);
	free(e->img);
	free(e->mlx);
	free(e);
	exit(0);
	return (0);
}

int				key_press(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		press_destroy(e);
	if (keycode == KEY_LEFT)
		e->t_dx = -1;
	if (keycode == KEY_RIGTH)
		e->t_dx = 1;
	if (keycode == KEY_UP)
		e->t_dy = -1;
	if (keycode == KEY_DOWN)
		e->t_dy = 1;
	if (keycode == KEY_PLUS)
		e->t_zoom = -1;
	if (keycode == KEY_MOIN)
		e->t_zoom = 1;

	return (0);
}

int				key_release(int keycode, t_env *e)
{
	if (keycode == KEY_LEFT)
		e->t_dx = 0;
	if (keycode == KEY_RIGTH)
		e->t_dx = 0;
	if (keycode == KEY_UP)
		e->t_dy = 0;
	if (keycode == KEY_DOWN)
		e->t_dy = 0;
	if (keycode == KEY_PLUS)
		e->t_zoom = 0;
	if (keycode == KEY_MOIN)
		e->t_zoom = 0;

	return (0);
}

int				loop(t_env *e)
{
	if (e->t_dx == 1)
		e->dx += 0.01;
	if (e->t_dx == -1)
		e->dx += -0.01;
	if (e->t_dy == 1)
		e->dy += 0.01;
	if (e->t_dy == -1)
		e->dy += -0.01;
	if (e->t_zoom == 1)
		e->zoom += 1.0;
	if (e->t_zoom == -1)
		e->zoom += -1.0;
	printf("%f\n", e->dy);
	put_img(e);
	return (0);
}
