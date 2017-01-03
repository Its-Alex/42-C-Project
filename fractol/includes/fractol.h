/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:22:52 by malexand          #+#    #+#             */
/*   Updated: 2017/01/03 15:51:42 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <pthread.h>
# include <limits.h>
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
	float		x;
	float		y;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		c_r;
	float		c_i;
	float		z_r;
	float		z_i;
	float		tmp;

	float		i;
}				t_frac;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;

	int			heigth;
	int			width;
	int			t_dx;
	int			t_dy;
	int			t_zoom;
	int			t_imax;
	int			reload;

	int			color;

	float		dx;
	float		dy;
	float		zoomx;
	float		zoomy;
	float		zoom;
	float		imax;
}				t_env;

typedef struct	s_thread
{
	pthread_t	thread1;
	pthread_t	thread2;
	pthread_t	thread3;
	pthread_t	thread4;
	pthread_t	thread5;
	pthread_t	thread6;
	pthread_t	thread7;
	pthread_t	thread8;
}				t_thread;

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
	KEY_RIGTH = 124,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_PLUS = 78,
	KEY_MOIN = 69,
	KEY_ESC = 53
}				t_mlx_key;

/*
** Fractal :
*/

void			init_mandel(t_env *e, t_frac *m);
void			init_julia(t_env *e, t_frac *m);
void			do_mandel(t_env *e, t_frac *m);
void			do_julia(t_env *e, t_frac *m);
void			julia(t_env *e);
void			*mandelbrot_hd(void *env);
void			*mandelbrot_hg(void *env);
void			*mandelbrot_bg(void *env);
void			*mandelbrot_bd(void *env);
void			*mandelbrot_hd1(void *env);
void			*mandelbrot_hg1(void *env);
void			*mandelbrot_bg1(void *env);
void			*mandelbrot_bd1(void *env);

/*
** Event func :
*/

int				key_press(int keycode, t_env *mlx);
int				key_release(int keycode, t_env *mlx);
int				loop(t_env *mlx);
int				press_destroy(t_env *env);

/*
** Put mlx func :
*/

int				put_img(t_env *env);
void			mlx_pixel_put_img(unsigned int color, t_env *e, int x, int y);
void			mlx_put_line(t_env *env, t_point *p1, t_point *p2);

/*
** Mlx func :
*/

t_point			*new_point(int x, int y, char *z, int color);
t_img			*init_img(t_env *env);
t_env			*init_env(int width, int heigth);

#endif
