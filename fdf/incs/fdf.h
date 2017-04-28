/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:12:25 by malexand          #+#    #+#             */
/*   Updated: 2017/04/28 14:50:14 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "../libft/incs/libft.h"
# include "keys.h" 
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <errno.h>
# include <pthread.h>
# include <limits.h>

typedef struct	s_img
{
	void			*img;
	char			*addr;

	int				bpp;
	int				size_l;
	int				endian;
}				t_img;

typedef struct	s_point
{
	int				px;
	int				py;

	int				x;
	int				y;
	int				z;

	unsigned int	color;
}				t_point;

typedef struct	s_mlx
{
	void			*mlx;
	void			*win;
	t_img			*img;

	int				heigth;
	int				width;

	int				diag;
	float			zoom;
	int				prof;
	int				decalx;
	int				decaly;
	int				t_zoom;
	int				t_prof;
	int				t_decalx;
	int				t_decaly;

	int				color;

	t_point			***point;
}				t_mlx;

typedef struct	s_bres
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;

	int				dx;
	int				dy;
	int				err;
	int				e2;
	int				sx;
	int				sy;
	int				degrad;

	int				color;
}				t_bres;

typedef struct	s_put
{
	int				line;
	int				column;
	int				mcolumn;
	int				mline;
}				t_put;

/*
** Init funcs :
*/

t_point			*new_point(int x, int y, char *z, int color);
t_img			*init_img(t_mlx *mlx);
t_mlx			*init_mlx(t_mlx *mlx, int w, int h);

/*
** Mlx put funcs:
*/

int				put_img(t_mlx *mlx);
void			*p_put_img_hg(void *arg);
void			*p_put_img_hd(void *arg);
void			*p_put_img_bg(void *arg);
void			*p_put_img_bd(void *arg);
void			put_menu(t_mlx *mlx);
void			mlx_pixel_put_img(unsigned long color, t_mlx *mlx,
					int x, int y);
void			mlx_put_line(t_mlx *mlx, t_point *p1, t_point *p2);
void			low_z(t_mlx *mlx);

/*
** Events funcs:
*/

int				press_destroy(t_mlx *mlx);
int				key_press(int keycode, t_mlx *mlx);
int				key_release(int keycode, t_mlx *mlx);
int				loop(t_mlx *mlx);

/*
** Parse & check funcs :
*/

void			check(char	*str);
t_point			***str_to_point(t_mlx *mlx, char *str);

/*
** Mlx funcs:
*/

t_mlx			*reset_mlx(t_mlx *mlx);

#endif
