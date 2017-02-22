/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:05:55 by malexand          #+#    #+#             */
/*   Updated: 2017/02/22 17:27:06 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		key_params(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		press_destroy(e);
}

int				key_press(int keycode, t_env *e)
{
	key_params(keycode, e);
	e->key.run = (keycode == KEY_W) ? 1 : e->key.run;
	e->key.run = (keycode == KEY_S) ? -1 : e->key.run;
	e->key.turn = (keycode == KEY_A) ? 1 : e->key.turn;
	e->key.turn = (keycode == KEY_D) ? -1 : e->key.turn;
	e->key.strafe = (keycode == KEY_Q) ? 1 : e->key.strafe;
	e->key.strafe = (keycode == KEY_E) ? -1 : e->key.strafe;
	return (0);
}

int				key_release(int keycode, t_env *e)
{
	key_params(keycode, e);
	e->key.run = (keycode == KEY_W || keycode == KEY_S) ? 0 : e->key.run;
	e->key.turn = (keycode == KEY_A || keycode == KEY_D)
		? 0 : e->key.turn;
	e->key.strafe = (keycode == KEY_Q || keycode == KEY_E)
		? 0 : e->key.strafe;
	return (0);
}
