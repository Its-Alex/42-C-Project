/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:22:52 by malexand          #+#    #+#             */
/*   Updated: 2016/12/09 12:15:54 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include "../libft/includes/libft.h"

typedef struct	s_img
{
	void		*img;
	char		*addr;

	int			bpp;
	int			size_l;
	int			endian;
}				t_img;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_frac
{
	double		x;
	double		y;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;

	double		i;
	double		i_max;
}				t_frac;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;

	int			heigth;
	int			width;
	int			dx;
	int			dy;
	int			reload;

	int			color;

	t_frac		m;

	double		zoomx;
	double		zoomy;
}				t_env;

/*
** Mlx keycode link
*/

typedef enum	e_mlx_key
{
	KEY_A = 0,
	KEY_B = 11,
	KEY_C = 8,
	KEY_D = 2,
	KEY_E = 14,
	KEY_F = 3,
	KEY_G = 5,
	KEY_H = 4,
	KEY_I = 34,
	KEY_J = 38,
	KEY_K = 40,
	KEY_L = 37,
	KEY_M = 46,
	KEY_N = 45,
	KEY_O = 31,
	KEY_P = 35,
	KEY_Q = 12,
	KEY_R = 15,
	KEY_S = 1,
	KEY_T = 17,
	KEY_U = 32,
	KEY_V = 9,
	KEY_W = 13,
	KEY_X = 7,
	KEY_Y = 16,
	KEY_Z = 6,
	KEY_0 = 29,
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_4 = 21,
	KEY_5 = 23,
	KEY_6 = 22,
	KEY_7 = 26,
	KEY_8 = 28,
	KEY_9 = 25,
	KEY_NUM_0 = 82,
	KEY_NUM_1 = 83,
	KEY_NUM_2 = 84,
	KEY_NUM_3 = 85,
	KEY_NUM_4 = 86,
	KEY_NUM_5 = 87,
	KEY_NUM_6 = 88,
	KEY_NUM_7 = 89,
	KEY_NUM_8 = 91,
	KEY_NUM_9 = 92,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_ESC = 53
}				t_mlx_key;

/*
** Fractal :
*/

void			mandelbrot(t_env *e);

/*
** Event func :
*/

int				my_keyfunc(int keycode, t_env *env);
int				press_destroy(t_env *env);

/*
** Put mlx func :
*/

int				put_img(t_env *env);
void			mlx_pixel_put_img(unsigned int color, t_img *img, int x, int y);
void			mlx_put_line(t_env *env, t_point *p1, t_point *p2);

/*
** Mlx func :
*/

t_point			*new_point(int x, int y, char *z, int color);
t_img			*init_img(t_env *env);
t_env			*init_env(int width, int heigth);

#endif
