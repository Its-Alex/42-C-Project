/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:47:36 by malexand          #+#    #+#             */
/*   Updated: 2017/02/21 16:59:16 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_img		*init_texture(t_env *e, char *name)
{
	t_img		*img;

	if ((img = (t_img *)malloc(sizeof(t_img))) == NULL)
		error(1, 0, "Malloc struct img!");
	img->img = mlx_xpm_file_to_image(e->mlx, ft_strjoin("pics/", name)
		, &img->x, &img->y);
	if (img->img == NULL)
		error(1, 0, "Init texture!");
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_l),
		&(img->endian));
	return (img);
}

t_img		*swap_texture(t_img *img)
{
	int		x;
	int		y;
	int		count;

	x = 0;
	while (x <= img->size_l / 4)
	{
		y = 0;
		while (y <= x)
		{
			count = 0;
			while (count < 4)
			{
				ft_swap_char(&img->addr[img->size_l * y + x * 4 + count],
					&img->addr[img->size_l * x + y * 4 + count]);
				count++;
			}
			y++;
		}
		x++;
	}
	return (img);
}

int			get_color(t_img *img, int x, int y)
{
	int		r;
	int		g;
	int		b;

	if (img->endian == 0)
	{
		b = (int)img->addr[y * img->size_l + x * img->bpp / 8];
		g = (int)img->addr[y * img->size_l + x * img->bpp / 8 + 1];
		r = (int)img->addr[y * img->size_l + x * img->bpp / 8 + 2];
	}
	else
	{
		r = (int)img->addr[y * img->size_l + x * img->bpp / 8];
		g = (int)img->addr[y * img->size_l + x * img->bpp / 8 + 1];
		b = (int)img->addr[y * img->size_l + x * img->bpp / 8 + 2];
	}
	return (RGB(r, g, b));
}
