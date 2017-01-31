/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:36:48 by malexand          #+#    #+#             */
/*   Updated: 2017/01/31 15:54:02 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		free_tab(char ***str)
{
	int		line;
	int		column;

	line = 0;
	column = 0;
	if (str == NULL)
	{
		ft_putendl("TEST");
		return ;
	}
	while (str[line])
	{
		column = 0;
		while (str[line][column])
		{
			ft_strdel(&str[line][column]);
			column++;
		}
		free(str[line]);
		line++;
	}
	free(str);
}

int				press_destroy(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img->img);
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_window(e->mlx, e->win);
	free_tab(e->map);
	free(e->img);
	free(e->mlx);
	free(e);
	exit(0);
	return (0);
}

int				fps(t_env *e)
{
	static double	last_time;
	static int		img;
	static int		save;
	double			current_time;
	char			*fps;

	current_time = time(NULL);
	if (e->init == 0)
	{
		last_time = current_time;
		save = 0;
		img = 0;
		e->init = 1;
	}
	img++;
	if (last_time != current_time)
	{
		last_time = current_time;
		save = img;
		img = 0;
	}
	fps = ft_itoa(save);
	mlx_string_put(e->mlx, e->win, 20, 20, 0xFFFFFF, fps);
	ft_strdel(&fps);
	return (0);
}

int				loop(t_env *e)
{
	put_img(e);
	fps(e);
	return (0);
}
