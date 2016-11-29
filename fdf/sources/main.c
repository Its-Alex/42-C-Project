/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:06:14 by malexand          #+#    #+#             */
/*   Updated: 2016/11/29 18:22:47 by malexand         ###   ########.fr       */
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
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(params->mlx, params->win);
		exit(0);
	}
	printf("Key event : %d\n", keycode);
	return (0);
}

int		draw(t_params * params)
{
	int		count;

	count = 0;
	params->img = init_img(params);
	ft_putnbr(params->img->bpp);
	ft_putendl("");
	ft_putnbr(params->img->size_l);
	ft_putendl("");
	ft_putnbr(params->img->endian);
	ft_putendl("");
	while (params->img->addr[count])
	{
		params->img->addr[count] = 0xFF;
		count++;
	}
	mlx_put_image_to_window(params->mlx, params->win, params->img->img, 500, 500);
	return (0);
}

int		main(int argc, char **argv)
{
	t_params	*params;

	(void)argc;
	params = (t_params *)malloc(sizeof(t_params));
	params = init_mlx(params, argv, 500, 500);
	mlx_expose_hook(params->win, draw, params);
	mlx_loop(params->mlx);
	/*if (argc != 2)
	{
		error(1, 0, "Wrong number of params!");
	}
	else
	{
		parse_file(argv[1]);
	}*/
	return (0);
}
