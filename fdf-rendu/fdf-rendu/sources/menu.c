/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:19:41 by malexand          #+#    #+#             */
/*   Updated: 2016/12/06 15:39:17 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_menu(t_mlx *mlx)
{
	int		color;

	if (mlx->color == 1)
		color = 0xFFFFFF;
	if (mlx->color == 2)
		color = 0xFF0000;
	if (mlx->color == 3)
		color = 0x00000FF;
	if (mlx->color == 4)
		color = 0x00FF00;
	mlx_string_put(mlx->mlx, mlx->win, 20, 20, color, "Trace diagonal : D");
	mlx_string_put(mlx->mlx, mlx->win, 20, 40, color, "Change color : C");
	mlx_string_put(mlx->mlx, mlx->win, 20, 80, color, "Etirer axe y : 1/2");
	mlx_string_put(mlx->mlx, mlx->win, 20, 100, color, "Etirer axe x : 3/4");
	mlx_string_put(mlx->mlx, mlx->win, 20, 60, color, "Profondeur : 6/7");
	mlx_string_put(mlx->mlx, mlx->win, 20, 120, color, "Quitter : Esc");
}
