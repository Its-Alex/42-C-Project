/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:23:36 by malexand          #+#    #+#             */
/*   Updated: 2017/01/09 13:24:18 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	int		env_main(void)
{
	t_env	*e;

	e = init_env(0, 0);
	put_img(e);
	mlx_hook(e->win, 2, 1L << 0, key_press, e);
	mlx_hook(e->win, 3, 1L << 1, key_release, e);
	mlx_hook(e->win, 17, 0L, press_destroy, e);
	mlx_hook(e->win, 4, 0L, mouse_button, e);
	mlx_loop_hook(e->mlx, loop, e);
	mlx_loop(e->mlx);
	return (0);
}

int				main(int argc, char **argv)
{
	if (argc != 2)
	{
		error(1, 0, "Wrong number of args!\n\tYou can use the following\
			arguments:\n\t\tMandelbrot\n\t\tJulia");
	}
	else
	{
		if (ft_strcmp(argv[1], "Mandelbrot") != 0 &&
				ft_strcmp(argv[1], "Julia") != 0)
			error(1, 0, "Bad args!\n\tYou can use the following arguments: \
				\n\t\tMandelbrot\n\t\tJulia\n\t\tJe sais pas encore");
		env_main();
	}
	return (0);
}
