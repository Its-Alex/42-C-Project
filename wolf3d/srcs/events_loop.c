/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:36:48 by malexand          #+#    #+#             */
/*   Updated: 2017/02/16 14:59:45 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				press_destroy(t_env *e)
{
	mlx_destroy_image(e->mlx, e->view->img);
	mlx_destroy_image(e->mlx, e->mmap->img);
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_window(e->mlx, e->win);
	free_tab(e->map->mapget);
	free(e->persp);
	free(e->map);
	free(e->view);
	free(e->mmap);
	free(e->mlx);
	free(e);
	exit(0);
	return (0);
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

int				loop(t_env *e)
{
	key_move(e);
	put_img(e);
	fps(e);
	return (0);
}
