/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:51:48 by malexand          #+#    #+#             */
/*   Updated: 2017/02/02 17:43:12 by malexand         ###   ########.fr       */
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
**
**	static void		put_int_array(t_map *map)
**	{
**		int		line;
**		int		column;
**
**		line = 0;
**		column = 0;
**		while (line < map->y)
**		{
**			column = 0;
**			while (column < map->x)
**			{
**				printf("%d ", map->mapgen[line][column]);
**				column++;
**			}
**			printf("\n");
**			line++;
**		}
**	}
*/

static void		put_int_array(t_map *map)
{
	int		line;
	int		column;

	line = 0;
	column = 0;
	while (line < map->y)
	{
		column = 0;
		while (column < map->x)
		{
			printf("%d ", map->mapgen[line][column]);
			column++;
		}
		printf("\n");
		line++;
	}
}

int				main(int argc, char **argv)
{
	t_env	*e;

	if (argc != 2 && argc != 1)
		error(1, 0, "Wrong number of arguments!");
	e = init_env(argv[1]);
	put_int_array(e->map);
	mlx_hook(e->win, 2, 1L << 0, key_press, e);
	mlx_hook(e->win, 3, 1L << 1, key_release, e);
	mlx_hook(e->win, 17, 0L, press_destroy, e);
	mlx_hook(e->win, 4, 0L, mouse_button, e);
	mlx_hook(e->win, 6, 0L, mouse_motion, e);
	mlx_loop_hook(e->mlx, loop, e);
	mlx_loop(e->mlx);
	return (0);
}
