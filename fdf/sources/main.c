/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:06:14 by malexand          #+#    #+#             */
/*   Updated: 2016/12/05 18:26:41 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			reset_mlx(t_mlx *mlx)
{
	mlx->mapw = 0;
	mlx->maph = 0;
	mlx->prof = 10;
	mlx->decaly = 0;
	mlx->decalx = 0;
	mlx->persp = 10;
	mlx->diff = 1;
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
	mlx->persp = (keycode == KEY_1) ? mlx->persp : mlx->persp + 1;
	mlx->persp = (keycode == KEY_2) ? mlx->persp : mlx->persp - 1;
	mlx->prof = (keycode == KEY_3) ? mlx->prof : mlx->prof + 1;
	mlx->prof = (keycode == KEY_4) ? mlx->prof : mlx->prof - 1;
	mlx->diff = (keycode == KEY_5) ? mlx->diff : mlx->diff + 1;
	mlx->diff = (keycode == KEY_6) ? mlx->diff : mlx->diff - 1;
	mlx->decalx = (keycode == KEY_LEFT) ? mlx->decalx : mlx->decalx + 10;
	mlx->decalx = (keycode == KEY_RIGHT) ? mlx->decalx : mlx->decalx - 10;
	mlx->decaly = (keycode == KEY_UP) ? mlx->decaly : mlx->decaly + 10;
	mlx->decaly = (keycode == KEY_DOWN) ? mlx->decaly : mlx->decaly - 10;
	if (keycode == KEY_R)
		reset_mlx(mlx);
	ft_bzero(mlx->img->addr, mlx->heigth * mlx->img->size_l +
		mlx->width * mlx->img->bpp / 8 + 2);
	put_img(mlx);
	printf("Key event : %d\n", keycode);
	return (0);
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
		str = ft_strjoin_free_endl(str, tmp);
	if (ret == -1)
		error(1, 1, "");
	ft_strdel(&tmp);
	if (close(fd) < 0)
		error(1, 1, "");
	return (str);
}

static	void		mlx_main(char *str)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx = init_mlx(mlx, 2048, 1080);
	mlx->point = str_to_point(mlx, str);
	mlx->img = init_img(mlx);
	put_img(mlx);
	mlx_hook(mlx->win, 2, 1L << 0, my_keyfunc, mlx);
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
