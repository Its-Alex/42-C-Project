/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:24:18 by malexand          #+#    #+#             */
/*   Updated: 2017/02/20 17:06:24 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		free_tab(char ***str)
{
	int		line;
	int		column;

	line = 0;
	column = 0;
	if (str == NULL)
		return ;
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

int			fps(t_env *e)
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
	mlx_string_put(e->mlx, e->win, e->width - 35, 9, 0xFFFFFF, fps);
	ft_strdel(&fps);
	return (0);
}
