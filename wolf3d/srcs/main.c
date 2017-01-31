/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:51:48 by malexand          #+#    #+#             */
/*   Updated: 2017/01/31 17:16:43 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
**	static	void	put_str_array(char ***array)
**	{
**		int		line;
**		int		column;
**
**		line = 0;
**		column = 0;
**		while (array[line])
**		{
**			column = 0;
**			while (array[line][column])
**			{
**				printf("%s ", array[line][column]);
**				column++;
**			}
**			printf("\n%d, %d\n", line, column);
**			line++;
**		}
**	}
*/

static	void	put_str_array(char ***array)
{
	int		line;
	int		column;

	line = 0;
	column = 0;
	while (array[line])
	{
		column = 0;
		while (array[line][column])
		{
			printf("%s ", array[line][column]);
			column++;
		}
		printf("\n%d, %d\n", line, column);
		line++;
	}
}

int				main(int argc, char **argv)
{
	t_env	*e;

	if (argc != 2)
		error(1, 0, "Wrong number of arguments!");
	e = init_env(0, 0, argv[1]);
	put_str_array(e->map);
	mlx_hook(e->win, 2, 1L << 0, key_press, e);
	mlx_hook(e->win, 3, 1L << 1, key_release, e);
	mlx_hook(e->win, 17, 0L, press_destroy, e);
	mlx_hook(e->win, 4, 0L, mouse_button, e);
	mlx_hook(e->win, 6, 0L, mouse_motion, e);
	mlx_loop_hook(e->mlx, loop, e);
	mlx_loop(e->mlx);
	return (0);
}
