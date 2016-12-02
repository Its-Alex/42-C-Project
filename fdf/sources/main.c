/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:06:14 by malexand          #+#    #+#             */
/*   Updated: 2016/12/02 17:37:57 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
		str = ft_strjoin_free_endl(str, tmp);
	if (ret == -1)
		error(1, 1, "");
	ft_strdel(&tmp);
	if (close(fd) < 0)
		error(1, 1, "");
	return (str);
}

int				my_keyfunc(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx);
		exit(0);
	}
	if (keycode == KEY_1)
	{
		mlx->sinus += 0.1;
		mlx->cosinus += 0.1;
		mlx_destroy_image(mlx->mlx, mlx->img);
		put_img(mlx);
	}
	if (keycode == KEY_2)
	{
		mlx->sinus -=  0.1;
		mlx->cosinus -= 0.1;
		mlx_destroy_image(mlx->mlx, mlx->img);
		put_img(mlx);
	}
	printf("Key event : %d\n", keycode);
	return (0);
}

void			mlx_main(char *str)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx = init_mlx(mlx, 2048, 1080);
	mlx->point = str_to_point(mlx, str);
	put_img(mlx);
	mlx_key_hook(mlx->win, my_keyfunc, mlx);
	mlx_loop(mlx->mlx);
}

int				main(int argc, char **argv)
{
	char	*str;

	str = NULL;
	if (argc != 2)
	{
		error(1, 0, "Wrong number of mlx!");
	}
	else
	{
		str = take_str(argv[1], str);
		check(str);
		mlx_main(str);
	}
	return (0);
}
