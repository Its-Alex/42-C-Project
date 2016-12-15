/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:05:55 by malexand          #+#    #+#             */
/*   Updated: 2016/12/15 14:28:41 by malexand         ###   ########.fr       */
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
	return (0);
}

int				loop(t_env *e)
{
	if (e->t_dx == 1 && e->dx < INT_MAX - 3)
		e->dx += 2;
	if (e->t_dx == -1 && e->dx > INT_MIN + 3)
		e->dx += -2;
	if (e->t_dy == 1 && e->dy < INT_MAX - 3)
		e->dy += 2;
	if (e->t_dy == -1 && e->dy > INT_MIN + 3)
		e->dy += -2;
	put_img(e);
	return (0);
}
