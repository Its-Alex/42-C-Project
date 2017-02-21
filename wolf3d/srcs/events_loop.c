/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:36:48 by malexand          #+#    #+#             */
/*   Updated: 2017/02/21 15:26:24 by malexand         ###   ########.fr       */
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
	if (e->filename != NULL)
		ft_strdel(&e->filename);
	free(e->persp);
	free(e->map);
	free(e->view);
	free(e->mmap);
	free(e->mlx);
	free(e);
	exit(0);
	return (0);
}

int				loop(t_env *e)
{
	key_move(e, 0.05);
	put_img(e);
	fps(e);
	return (0);
}
