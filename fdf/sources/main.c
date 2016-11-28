/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:06:14 by malexand          #+#    #+#             */
/*   Updated: 2016/11/28 18:04:59 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error(int error, int send_perror, char *str)
{
	if (send_perror == 1)
	{
		ft_putstr_color("Error \x1B[0m: ", RED);
		perror("");
	}
	else
	{
		ft_putstr_color("Error", RED);
		ft_putstr(" : ");
		ft_putendl(str);
	}
	exit(error);
}

int		my_keyfunc(int keycode, t_params *params)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(params->mlx, params->win);
		exit(0);
	}
	printf("Key event : %d\n", keycode);
	return (0);
}

int		main(int argc, char **argv)
{
	t_params	*params;

	(void)argv;
	params = (t_params *)malloc(sizeof(t_params));
	// params->point = (t_point *)malloc(sizeof(t_point));
	// params->point->x = 50;
	// params->point->y = 50;
	// ft_putnbr(params->point->y);
	if (argc != 2)
	{
		error(1, 0, "Wrong number of params!");
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
