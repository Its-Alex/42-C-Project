/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:21:24 by malexand          #+#    #+#             */
/*   Updated: 2016/12/01 16:45:11 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_point		**point_line(char ***array_str, int line)
{
	int			count;
	t_point		**p;

	count = 0;
	while (array_str[line][count])
		count++;
	if ((p = (t_point **)malloc(sizeof(t_point*) * (count)))
			== NULL)
		error(1, 0, "Wrong malloc point");
	count = 0;
	while (array_str[line][count])
	{
		p[count] = new_point(line + 1, count + 1,
			array_str[line][count], 0xFFFFFF);
		count++;
	}
	p[count] = NULL;
	free(array_str[line]);
	return (p);
}

t_point				***str_to_point(t_mlx *mlx)
{
	int		line;
	char	***array_str;

	line = 0;
	array_str = parse_array_3d(mlx->str, '\n', ' ');
	while (array_str[line])
		line++;
	if ((mlx->point = (t_point ***)malloc(sizeof(t_point**) *
			(line))) == NULL)
		error(1, 0, "Wrong malloc point");
	line = 0;
	while (array_str[line])
	{
		mlx->point[line] = point_line(array_str, line);
		line++;
	}
	mlx->point[line] = NULL;
	free(array_str);
	return (mlx->point);
}
