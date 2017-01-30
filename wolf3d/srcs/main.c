/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:51:48 by malexand          #+#    #+#             */
/*   Updated: 2017/01/30 19:39:03 by skyzie           ###   ########.fr       */
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

char			***get_map(t_env *e, char *file)
{
	char	*str;

	str = NULL;
	str = take_str(file, str);
	if (str == NULL)
		error(1, 0, "Bad map format!");
	e->map = parse_array_3d(str, '\n', ' ');
	ft_strdel(&str);
	if (e->map == NULL)
		error(1, 0, "Bad parsing!");
	return (e->map);
}

int				main(int argc, char **av)
{
	t_env	*e;

	if (argc != 2 && argc != 4)
		error(1, 0, "Wrong number of arguments!");
	if (argc == 4)
		e = init_env(ft_atoi(av[2]), ft_atoi(av[3]), av);
	else
		e = init_env(0, 0, av);
	mlx_hook(e->win, 2, 1L << 0, key_press, e);
	mlx_hook(e->win, 3, 1L << 1, key_release, e);
	mlx_hook(e->win, 17, 0L, press_destroy, e);
	mlx_hook(e->win, 4, 0L, mouse_button, e);
	mlx_hook(e->win, 6, 0L, mouse_motion, e);
	mlx_loop_hook(e->mlx, loop, e);
	mlx_loop(e->mlx);
	return (0);
}
