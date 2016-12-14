/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:06:14 by malexand          #+#    #+#             */
/*   Updated: 2016/12/14 14:49:41 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx			*reset_mlx(t_mlx *mlx)
{
	mlx->decaly = 0;
	mlx->decalx = 0;
	mlx->diag = 0;
	mlx->color = 4;
	return (mlx);
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
	ft_putstr(str);
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
	mlx->img = init_img(mlx);
	put_img(mlx);
	mlx_hook(mlx->win, 2, 1L << 0, my_keyfunc, mlx);
	mlx_hook(mlx->win, 17, 0L, press_destroy, mlx);
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
