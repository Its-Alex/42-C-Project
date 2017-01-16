/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:05:55 by malexand          #+#    #+#             */
/*   Updated: 2017/01/16 14:48:27 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			key_params(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		press_destroy(e);
	if (keycode == KEY_W)
		env_main(e->av);
	if (keycode == KEY_R)
		reset(e);
	if (keycode == KEY_P)
		e->move = (e->move != 1) ? 1 : 0;
	if (keycode == KEY_C && e->color < 12000000000)
		e->color *= 13;
	if (e->color > 1200000000)
		e->color = 255;
	if (keycode == KEY_V)
		e->color_mod = (e->color_mod != 1) ? 1 : 0;
	if (keycode == KEY_NUM_1)
		e->color = 255;
	if (keycode == KEY_NUM_2)
		e->color = 255 << 8;
	if (keycode == KEY_NUM_3)
		e->color = 255 << 16;
}

void			key_fract(int keycode, t_env *e)
{
	if (keycode == KEY_1)
		e->av[1] = "Mandelbrot";
	if (keycode == KEY_2)
		e->av[1] = "Julia";
	if (keycode == KEY_3)
		e->av[1] = "BurningShip";
	if (keycode == KEY_4)
		e->av[1] = "Douady";
	if (keycode == KEY_5)
		e->av[1] = "Tricorn";
	if (keycode == KEY_6)
		e->av[1] = "Chameleon";
	if (keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3
			|| keycode == KEY_4 || keycode == KEY_5 || keycode == KEY_6)
		reset(e);
}

int				key_press(int keycode, t_env *e)
{
	key_fract(keycode, e);
	key_params(keycode, e);
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
	if (keycode == KEY_NUM_7)
		e->t_imax = -1;
	if (keycode == KEY_NUM_9)
		e->t_imax = 1;
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
	if (keycode == KEY_NUM_7)
		e->t_imax = 0;
	if (keycode == KEY_NUM_9)
		e->t_imax = 0;
	return (0);
}
