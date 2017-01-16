/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:10:53 by malexand          #+#    #+#             */
/*   Updated: 2017/01/16 14:45:17 by malexand         ###   ########.fr       */
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

static	void	thread_work(t_thread *t, t_env *e)
{
	if (pthread_create(&t->thread1, NULL, hg, e) == -1)
		error(1, 1, "");
	if (pthread_create(&t->thread2, NULL, hd, e) == -1)
		error(1, 1, "");
	if (pthread_create(&t->thread3, NULL, bg, e) == -1)
		error(1, 1, "");
	if (pthread_create(&t->thread4, NULL, bd, e) == -1)
		error(1, 1, "");
	if (pthread_create(&t->thread5, NULL, hg1, e) == -1)
		error(1, 1, "");
	if (pthread_create(&t->thread6, NULL, hd1, e) == -1)
		error(1, 1, "");
	if (pthread_create(&t->thread7, NULL, bg1, e) == -1)
		error(1, 1, "");
	if (pthread_create(&t->thread8, NULL, bd1, e) == -1)
		error(1, 1, "");
}

static	void	thread_wait(t_thread *t)
{
	if (pthread_join(t->thread1, NULL))
		error(1, 1, "");
	if (pthread_join(t->thread2, NULL))
		error(1, 1, "");
	if (pthread_join(t->thread3, NULL))
		error(1, 1, "");
	if (pthread_join(t->thread4, NULL))
		error(1, 1, "");
	if (pthread_join(t->thread5, NULL))
		error(1, 1, "");
	if (pthread_join(t->thread6, NULL))
		error(1, 1, "");
	if (pthread_join(t->thread7, NULL))
		error(1, 1, "");
	if (pthread_join(t->thread8, NULL))
		error(1, 1, "");
}

static	void	create_img(t_env *e)
{
	static t_thread		t;

	thread_work(&t, e);
	thread_wait(&t);
}

int				put_img(t_env *e)
{
	ft_bzero(e->img->addr, e->img->size_l * e->heigth);
	create_img(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
	return (0);
}
