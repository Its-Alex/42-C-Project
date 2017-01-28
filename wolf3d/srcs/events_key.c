/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:05:55 by malexand          #+#    #+#             */
/*   Updated: 2017/01/25 17:29:10 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/wolf.h"

int				key_press(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		press_destroy(e);
	return (0);
}

int				key_release(int keycode, t_env *e)
{
	(void)keycode;
	(void)e;
	return (0);
}