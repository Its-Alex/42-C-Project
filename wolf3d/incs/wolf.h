/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:50:59 by malexand          #+#    #+#             */
/*   Updated: 2017/01/28 19:23:04 by skyzie           ###   ########.fr       */
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
# include "keys.h"

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

int				mouse_button(int button, int x, int y, t_env *e);
int				mouse_motion(int x, int y, t_env *e);
int				key_release(int keycode, t_env *e);
int				key_press(int keycode, t_env *e);
int				put_img(t_env *e);
int				press_destroy(t_env *e);
int				loop(t_env *e);
t_env			*init_env(int width, int heigth, char **av);

#endif
