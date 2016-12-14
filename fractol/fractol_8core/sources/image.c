/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:10:53 by malexand          #+#    #+#             */
/*   Updated: 2016/12/14 15:26:31 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			mlx_pixel_put_img(unsigned int color, t_env *e, int x, int y)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0x00FF00) >> 8);
	b = (color & 0x0000FF);
	if (x >= 0 && x < e->width && y >= 0 && y < e->heigth)
	{
		if (e->img->endian == 0)
		{
			e->img->addr[y * e->img->size_l + x * e->img->bpp / 8] = b;
			e->img->addr[y * e->img->size_l + x * e->img->bpp / 8 + 1] = g;
			e->img->addr[y * e->img->size_l + x * e->img->bpp / 8 + 2] = r;
		}
		else if (e->img->endian == 1)
		{
			e->img->addr[y * e->img->size_l + x * e->img->bpp / 8] = r;
			e->img->addr[y * e->img->size_l + x * e->img->bpp / 8 + 1] = g;
			e->img->addr[y * e->img->size_l + x * e->img->bpp / 8 + 2] = b;
		}
	}
}

static	void	create_img(t_env *e)
{
	pthread_t	thread1;
	pthread_t	thread2;
	pthread_t	thread3;
	pthread_t	thread4;
	pthread_t	thread5;
	pthread_t	thread6;
	pthread_t	thread7;
	pthread_t	thread8;

	if (pthread_create(&thread1, NULL, mandelbrot_hg, e) == -1)
		error(1, 1, "");
	if (pthread_create(&thread2, NULL, mandelbrot_hd, e) == -1)
		error(1, 1, "");
	if (pthread_create(&thread3, NULL, mandelbrot_bg, e) == -1)
		error(1, 1, "");
	if (pthread_create(&thread4, NULL, mandelbrot_bd, e) == -1)
		error(1, 1, "");
	if (pthread_create(&thread5, NULL, mandelbrot_hg1, e) == -1)
		error(1, 1, "");
	if (pthread_create(&thread6, NULL, mandelbrot_hd1, e) == -1)
		error(1, 1, "");
	if (pthread_create(&thread7, NULL, mandelbrot_bg1, e) == -1)
		error(1, 1, "");
	if (pthread_create(&thread8, NULL, mandelbrot_bd1, e) == -1)
		error(1, 1, "");
	if (pthread_join(thread1, NULL))
		error(1, 1, "");
	if (pthread_join(thread2, NULL))
		error(1, 1, "");
	if (pthread_join(thread3, NULL))
		error(1, 1, "");
	if (pthread_join(thread4, NULL))
		error(1, 1, "");
	if (pthread_join(thread5, NULL))
		error(1, 1, "");
	if (pthread_join(thread6, NULL))
		error(1, 1, "");
	if (pthread_join(thread7, NULL))
		error(1, 1, "");
	if (pthread_join(thread8, NULL))
		error(1, 1, "");
}

int				put_img(t_env *e)
{
	ft_bzero(e->img->addr, e->img->size_l * e->heigth);
	create_img(e);
	if (e->reload++ == 0)
		e->win = mlx_new_window(e->mlx, e->width, e->heigth, "fractol");
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
	return (0);
}
