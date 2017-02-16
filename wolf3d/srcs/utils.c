/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:24:18 by malexand          #+#    #+#             */
/*   Updated: 2017/02/16 18:05:14 by malexand         ###   ########.fr       */
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

t_img			*swap_texture(t_img *img)
{
	int		x;
	int 	y;
	int 	count;

	x = 0;
	while (x <= img->size_l / 4)
	{
		y = 0;
		while (y <= x)
		{
			count = 0;
			while (count < 4)
			{
				ft_swap_char(&img->addr[img->size_l * y + x * 4 + count],
					&img->addr[img->size_l * x + y * 4 + count]);
				count ++;
			}
			y++;
		}
		x++;
	}
	return (img);
}

t_img		*put_trans(t_img *img)
{
	int		count;

	count = 0;
	mprintf(1, "%d, %d\n", img->size_l, img->y);
	while (count < img->size_l * img->y)
	{
		mprintf(1, "Salut\n");
		if (img->addr[count] == 0 && img->addr[count + 1] == 0 &&
			img->addr[count + 1] == 0)
		{
			img->addr[count + 0] = 255;
			img->addr[count + 1] = 255;
			img->addr[count + 2] = 255;
			img->addr[count + 3] = 255;
		}
		count += 4;
	}
	return (img);
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
