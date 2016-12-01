/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:06:14 by malexand          #+#    #+#             */
/*   Updated: 2016/12/01 17:48:37 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		my_keyfunc(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx);
		exit(0);
	}
	printf("Key event : %d\n", keycode);
	return (0);
}

void	mlx_launch(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, my_keyfunc, mlx);
	mlx_loop(mlx->mlx);
}

char	*take_str(char *av, t_mlx *mlx)
{
	int		fd;
	int		ret;
	char	*tmp;

	fd = 0;
	ret = 0;
	mlx->str = (char*)malloc(sizeof(char));
	mlx->str[0] = '\0';
	if ((fd = open(av, O_RDONLY)) < 0)
		error(1, 1, "");
	while ((ret = get_next_line(fd, &tmp)) == 1)
		mlx->str = ft_strjoin_free_endl(mlx->str, tmp);
	if (ret == -1)
		error(1, 1, "");
	ft_strdel(&tmp);
	if (close(fd) < 0)
		error(1, 1, "");
	return (mlx->str);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (argc != 2)
	{
		error(1, 0, "Wrong number of mlx!");
	}
	else
	{
		mlx = init_mlx(mlx, 500, 500);
		mlx->str = take_str(argv[1], mlx);
		//check(mlx->str);
		mlx->point = str_to_point(mlx);
		put_img(mlx);
		mlx_launch(mlx);
	}
	return (0);
}
