/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:51:48 by malexand          #+#    #+#             */
/*   Updated: 2017/01/25 18:51:21 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/wolf.h"

int		resize(t_env *e)
{
	(void)e;
	ft_putstr("Test");
	return (0);
}

int		main(int argc, char **av)
{
	t_env	*e;

	(void)argc;
	e = init_env(ft_atoi(av[2]), ft_atoi(av[3]), av);
	mlx_hook(e->win, 2, 1L << 0, key_press, e);
	mlx_hook(e->win, 3, 1L << 1, key_release, e);
	mlx_hook(e->win, 17, 0L, press_destroy, e);
	mlx_hook(e->win, 4, 0L, mouse_button, e);
	mlx_hook(e->win, 6, 0L, mouse_motion, e);
	mlx_loop_hook(e->mlx, loop, e);
	mlx_loop(e->mlx);
	return (0);
}
