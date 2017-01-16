/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:23:36 by malexand          #+#    #+#             */
/*   Updated: 2017/01/16 14:49:07 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				env_main(char **av)
{
	t_env	*e;

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

int				main(int argc, char **argv)
{
	if (argc != 2 && argc != 4)
	{
		error(1, 0, "Wrong number of args!\n\tYou can use the following \
			arguments:\n\t\tMandelbrot\n\t\tJulia\n\t\tBurningship \
			\n\t\tDouady\n\t\tTricorn\n\t\tChameleon");
	}
	else
	{
		if (ft_strcmp(argv[1], "Mandelbrot") != 0 &&
				ft_strcmp(argv[1], "Julia") != 0 &&
				ft_strcmp(argv[1], "BurningShip") != 0 &&
				ft_strcmp(argv[1], "Douady") != 0 &&
				ft_strcmp(argv[1], "Tricorn") != 0 &&
				ft_strcmp(argv[1], "Chameleon") != 0)
			error(1, 0, "Bad args!\n\tYou can use the following arguments: \
				\n\t\tMandelbrot\n\t\tJulia\n\t\tBurningship\n\t\tDouady \
				\n\t\tTricorn\n\t\tChameleon");
		env_main(argv);
	}
	return (0);
}
