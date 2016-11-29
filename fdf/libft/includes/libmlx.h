/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:53:00 by malexand          #+#    #+#             */
/*   Updated: 2016/11/29 18:00:01 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMLX_H
# define LIBMLX_H
# include <mlx.h>
# include <math.h>

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
	int			px;
	int			py;

	int			x;
	int			y;
	int			z;

	int			color;
}				t_point;

typedef struct	s_params
{
	void		*mlx;
	void		*win;
	t_img		*img;

	int			heigth;
	int			width;

	char		**av;
	char		**parse;

	t_point		**point;
}				t_params;

typedef struct	s_bresenham
{
	int			x;
	int			y;

	int			dx;
	int			dy;

	int			incx;
	int			incy;

	int			color;
}				t_bresenham;

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

t_params		*init_mlx(t_params *params, char **av, int w, int h);
t_img			*init_img(t_params *params);
void			bres(t_params *params, t_point point1, t_point point2);

#endif
