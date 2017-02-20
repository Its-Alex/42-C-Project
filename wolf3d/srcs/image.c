/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:10:53 by malexand          #+#    #+#             */
/*   Updated: 2017/02/20 16:17:01 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			mlx_pixel_put_img(unsigned int color, t_img *img, int x, int y)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0x00FF00) >> 8);
	b = (color & 0x0000FF);
	if (x >= 0 && x < img->x && y >= 0 && y < img->y)
	{
		if (img->endian == 0)
		{
			img->addr[y * img->size_l + x * img->bpp / 8] = b;
			img->addr[y * img->size_l + x * img->bpp / 8 + 1] = g;
			img->addr[y * img->size_l + x * img->bpp / 8 + 2] = r;
			img->addr[y * img->size_l + x * img->bpp / 8 + 3] = img->opacity;
		}
		else if (img->endian == 1)
		{
			img->addr[y * img->size_l + x * img->bpp / 8] = r;
			img->addr[y * img->size_l + x * img->bpp / 8 + 1] = g;
			img->addr[y * img->size_l + x * img->bpp / 8 + 2] = b;
			img->addr[y * img->size_l + x * img->bpp / 8 + 3] = img->opacity;
		}
	}
}

t_img			*init_texture(t_env *e, char *name, int width, int height)
{
	t_img		*img;

	if ((img = (t_img *)malloc(sizeof(t_img))) == NULL)
		error(1, 0, "Malloc struct img!");
	img->img = mlx_xpm_file_to_image(e->mlx, ft_strjoin("pics/", name), &width, &height);
	if (img->img == NULL)
		error(1, 0, "Init texture!");
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_l),
		&(img->endian));
	img->x = width;
	img->y = height;
	img->opacity = 0;
	return (img);
}

void			draw_line(t_env *e, int x, int start, int stop,
	int texture_x)
{
	int		y;
	int		d;

	y = 0;
	while (y < e->height)
	{
		d = y * 256 - e->height * 128 + (stop - start) * 128;
		if (y >= stop)
			mlx_pixel_put_img(RGB(220, 220, 220), e->view, x, y);
		else if (y >= start)
			mlx_pixel_put_img(get_color(e->wood, texture_x, ((d * 64) / (stop - start)) / 256), e->view, x, y);
		else
			mlx_pixel_put_img(RGB(58, 142, 186), e->view, x, y);
		y++;
	}
}

int				put_img(t_env *e)
{
	minimap(e);
	ray_casting(e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->view->img, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->mmap->img, 15, 15);
	e->pillar->img = put_trans(e->pillar->img);
	mlx_put_image_to_window(e->mlx, e->win, e->pillar->img, 100, 100);
	return (0);
}
