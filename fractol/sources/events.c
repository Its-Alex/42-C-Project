/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:05:55 by malexand          #+#    #+#             */
/*   Updated: 2016/12/09 12:11:24 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void		free_func(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img->img);
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_window(e->mlx, e->win);
	free(e->img);
	free(e->mlx);
	free(e);
	exit(0);
}

int					press_destroy(t_env *e)
{
	free_func(e);
	return (0);
}

int					my_keyfunc(int keycode, t_env *e)
{
	ft_putstr("Key event : ");
	ft_putnbr(keycode);
	ft_putendl("");
	if (keycode == KEY_ESC)
		press_destroy(e);
	e->dy = (keycode == KEY_UP) ? e->dy : e->dy + 3;
	e->dy = (keycode == KEY_DOWN) ? e->dy : e->dy - 3;
	e->dx = (keycode == KEY_LEFT) ? e->dx : e->dx + 3;
	e->dx = (keycode == KEY_RIGHT) ? e->dx : e->dx - 3;
	put_img(e);
	return (0);
}
