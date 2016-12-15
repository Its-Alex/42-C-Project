/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:19:41 by malexand          #+#    #+#             */
/*   Updated: 2016/12/15 12:30:05 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_menu(t_mlx *mlx)
{
	int		color;

	color = 0xFFFFFF;
	mlx_string_put(mlx->mlx, mlx->win, 20, 20, color, "Diagonale ----> [D]");
	mlx_string_put(mlx->mlx, mlx->win, 20, 40, color, "Hide stage ---> [C]");
	mlx_string_put(mlx->mlx, mlx->win, 20, 60, color, "Zoom ---------> [+/-]");
	mlx_string_put(mlx->mlx, mlx->win, 20, 80, color, "Profondeur ---> [1/2]");
	mlx_string_put(mlx->mlx, mlx->win, 20, 100, color, "Quitter ------> [Esc]");
}
