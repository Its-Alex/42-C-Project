/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:37:18 by malexand          #+#    #+#             */
/*   Updated: 2017/01/31 15:12:22 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				mouse_button(int button, int x, int y, t_env *e)
{
	if (e == NULL)
		printf("%d, %d, %d\n", button, x, y);
	(void)e;
	return (0);
}

int				mouse_motion(int x, int y, t_env *e)
{
	if (e == NULL)
		printf("%d, %d\n", x, y);
	(void)e;
	return (0);
}
