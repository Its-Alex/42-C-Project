/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:05:55 by malexand          #+#    #+#             */
/*   Updated: 2017/01/09 16:56:25 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				mouse_button(int button, int x, int y, t_env *e)
{
	if (button == 1 || button == 5)
		zoom_in(e, x, y);
	if (button == 2 || button == 4)
		zoom_out(e, x, y);
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
