/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:06:14 by malexand          #+#    #+#             */
/*   Updated: 2016/12/14 19:31:46 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx			*reset_mlx(t_mlx *mlx)
{
	mlx->decaly = 0;
	mlx->decalx = 0;
	mlx->diag = 0;
	mlx->zoom = 30.0;
	mlx->prof = 2;
	return (mlx);
}

void			low_z(t_mlx *mlx)
{
	int		line;
	int		column;

	line = 0;
	column = 0;
	mlx->color = 0;
	while (mlx->point[line])
	{
		column = 0;
		while (mlx->point[line][column])
		{
			if (mlx->point[line][column]->z < mlx->color)
				mlx->point[line][column]->z = mlx->color;
			column++;
		}
		line++;
	}
}

static	char	*take_str(char *av, char *str)
{
	int		fd;
	int		ret;
	char	*tmp;

	fd = 0;
	ret = 0;
	str = (char*)malloc(sizeof(char));
	str[0] = '\0';
	if ((fd = open(av, O_RDONLY)) < 0)
		error(1, 1, "");
	while ((ret = get_next_line(fd, &tmp)) == 1)
	{
		str = ft_strjoin_free_endl(str, tmp);
		ft_strdel(&tmp);
	}
	if (ret == -1)
		error(1, 1, "");
	if (close(fd) < 0)
		error(1, 1, "");
	return (str);
}

static	void	mlx_main(char *str, char **av)
{
	t_mlx	*mlx;

	mlx = NULL;
	if (av[2] != NULL && av[3] != NULL)
		mlx = init_mlx(mlx, ft_atoi(av[2]), ft_atoi(av[3]));
	else
		mlx = init_mlx(mlx, 0, 0);
	mlx->point = str_to_point(mlx, str);
	ft_strdel(&str);
	low_z(mlx);
	mlx->img = init_img(mlx);
	put_img(mlx);
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win, 3, 1L << 1, key_release, mlx);
	mlx_hook(mlx->win, 17, 0L, press_destroy, mlx);
	mlx_loop_hook(mlx->mlx, loop, mlx);
	mlx_loop(mlx->mlx);
}

int				main(int argc, char **argv)
{
	char	*str;

	str = NULL;
	if (argc != 2 && argc != 4)
	{
		error(1, 0, "Wrong number of mlx!");
	}
	else
	{
		str = take_str(argv[1], str);
		check(str);
		mlx_main(str, argv);
	}
	return (0);
}
