/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:21:24 by malexand          #+#    #+#             */
/*   Updated: 2016/12/07 13:00:44 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	static	void		put_point(t_point ***point)
**	{
**		int		line;
**		int		column;
**
**		line = 0;
**		column = 0;
**		while (point[line])
**		{
**			column = 0;
**			while (point[line][column])
**			{
**				printf("%d ", point[line][column]->z);
**				column++;
**			}
**			printf("\n");
**			line++;
**		}
**	}
**
**	static	void		put_str_array(char ***array)
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

static	void		free_tab(char ***str)
{
	int		line;
	int		column;

	line = 0;
	column = 0;
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

static	t_point		**point_line(char ***array_str, int line)
{
	int			count;
	t_point		**p;

	count = 0;
	while (array_str[line][count])
		count++;
	if ((p = (t_point **)malloc(sizeof(t_point*) * (count + 1)))
			== NULL)
		error(1, 0, "Wrong malloc point");
	count = 0;
	while (array_str[line][count] != NULL)
	{
		p[count] = new_point(line + 1, count + 1,
			array_str[line][count], 0xFFFFFF);
		count++;
	}
	p[count] = NULL;
	return (p);
}

t_point				***str_to_point(t_mlx *mlx, char *str)
{
	int		line;
	char	***array_str;

	line = 0;
	array_str = parse_array_3d(str, '\n', ' ');
	while (array_str[line])
		line++;
	if ((mlx->point = (t_point ***)malloc(sizeof(t_point**) *
			(line + 1))) == NULL)
		error(1, 0, "Wrong malloc point");
	line = 0;
	while (array_str[line])
	{
		mlx->point[line] = point_line(array_str, line);
		line++;
	}
	mlx->point[line] = NULL;
	free_tab(array_str);
	return (mlx->point);
}
