/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:50:59 by malexand          #+#    #+#             */
/*   Updated: 2017/01/25 17:29:32 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <mlx.h>
# include <pthread.h>
# include <limits.h>
# include <time.h>
# include <math.h>
# include "../libft/incs/libft.h"

typedef struct	s_img
{
	void			*img;
	char			*addr;

	int				bpp;
	int				size_l;
	int				endian;
}				t_img;

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;

	char			**av;

	int				h;
	int				w;
	int				init;
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
	KEY_RIGTH = 124,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_PLUS = 78,
	KEY_MOIN = 69,
	KEY_ESC = 53
}				t_mlx_key;

int				mouse_button(int button, int x, int y, t_env *e);
int				mouse_motion(int x, int y, t_env *e);
int				key_release(int keycode, t_env *e);
int				key_press(int keycode, t_env *e);
int				put_img(t_env *e);
int				press_destroy(t_env *e);
int				loop(t_env *e);
t_env			*init_env(int width, int heigth, char **av);

#endif
