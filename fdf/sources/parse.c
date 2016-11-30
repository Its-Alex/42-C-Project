/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:21:24 by malexand          #+#    #+#             */
/*   Updated: 2016/11/30 18:24:56 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	int		size_tab(char ***array)
{
	int		line;
	int		column;

	line = 0;
	while (array[line])
	{
		column = 0;
		while (array[line][column])
			column++;
		line++;
	}
	return ((line - 1) * (column - 1));
}

static	void	put_point(t_point **p)
{
	int		count;

	count = 0;
	while (p[count])
	{
		printf("x : %d, y : %d\n", p[count]->x, p[count]->y);
		count++;
	}
}	

static	void	str_to_point(t_mlx *mlx, char ***tabstr)
{
	int		line;
	int		column;
	int		count;

	line = 0;
	count = 0;
	if ((mlx->point = (t_point **)malloc(sizeof(t_point) *
			(size_tab(tabstr) - 1))) == NULL)
		error(1, 0, "Wrong malloc point");
	while (tabstr[line])
	{
		column = 0;
		while (tabstr[line][column])
		{
			mlx->point[count] = new_point(line + 1, column + 1, tabstr[line][column]);
			column++;
			count++;
		}
		free(tabstr[line]);
		line++;
	}
	mlx->point[count] = NULL;
	free(tabstr);
}

static	char	***parse_str(t_mlx *mlx, char *str)
{
	char	***str_parse;

	str_parse = parse_array_3d(str, '\n', ' ');
	putarray_3d(str_parse);
	str_to_point(mlx, str_parse);
	put_point(mlx->point);
	return (NULL);
}

t_point			**parse(t_mlx *mlx, char **argv)
{
	int		fd;
	int		ret;
	char	*tmp;
	char	*str;

	fd = 0;
	ret = 0;
	str = (char*)malloc(sizeof(char));
	str[0] = '\0';
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		error(1, 1, "");
	while ((ret = get_next_line(fd, &tmp)) == 1)
		str = ft_strjoin_free_endl(str, tmp);
	if (ret == -1)
		error(1, 1, "");
	ft_strdel(&tmp);
	if (close(fd) < 0)
		error(1, 1, "");
	check(str);
	parse_str(mlx, str);
	free(str);
	return (mlx->point);
}
