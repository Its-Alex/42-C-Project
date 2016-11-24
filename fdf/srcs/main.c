/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:06:14 by malexand          #+#    #+#             */
/*   Updated: 2016/11/24 16:31:17 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int		my_keyfunc(int keycode, t_params *params)
{
	if (keycode == 53)
		exit(0);
	printf("Key event : %d\n", keycode);
	mlx_string_put(params->mlx, params->win, 10, 10, 0x0000FF, "Salut");
	mlx_destroy_window(params->mlx, params->win);
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
		ft_putstr(" : Wrong number of params\n");
	}
	else
	{
		parse_file(argv[1]);
		params = (t_params*)malloc(sizeof(t_params));
		params->mlx = mlx_init();
		params->win = mlx_new_window(params->mlx, 400, 400, "fdf");
		mlx_key_hook(params->win, my_keyfunc, params);
		mlx_loop(params->mlx);
	}
	return (0);
}
