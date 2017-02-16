/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:05:55 by malexand          #+#    #+#             */
/*   Updated: 2017/02/16 11:01:35 by malexand         ###   ########.fr       */
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
	e->key.run = (keycode == KEY_UP) ? 1 : e->key.run;
	e->key.run = (keycode == KEY_DOWN) ? -1 : e->key.run;
	e->key.turn = (keycode == KEY_LEFT) ? 1 : e->key.turn;
	e->key.turn = (keycode == KEY_RIGTH) ? -1 : e->key.turn;
	return (0);
}

int				key_release(int keycode, t_env *e)
{
	key_params(keycode, e);
	e->key.run = (keycode == KEY_UP || keycode == KEY_DOWN) ? 0 : e->key.run;
	e->key.turn = (keycode == KEY_LEFT || keycode == KEY_RIGTH)
		? 0 : e->key.turn;
	return (0);
}
