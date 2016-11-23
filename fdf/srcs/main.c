/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:06:14 by malexand          #+#    #+#             */
/*   Updated: 2016/11/23 18:12:29 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int		my_keyfunc(int keycode, t_params *params)
{
	if (keycode == 53)
		exit(0);
	printf("Key event : %d\n", keycode);
	(void)params;
	return (0);
}

int		main(int argc, char **argv)
{
	t_params	*params;

	(void)argv;
	params = (t_params*)malloc(sizeof(t_params));
	if (argc != 2)
	{
		ft_putstr_color("Error", RED);
		ft_putstr(" : wrong number of params\n");
	}
	else
	{
		parse_file(argv[1]);

		// params = (t_params*)malloc(sizeof(t_params));
		// params->mlx = mlx_init();
		// params->win = mlx_new_window(params->mlx, 400, 400, "fdf");
		// mlx_key_hook(params->win, my_keyfunc, 0);
		// mlx_loop(params->mlx);

	}
	return (0);
}