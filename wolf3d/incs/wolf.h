/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:50:59 by malexand          #+#    #+#             */
/*   Updated: 2017/01/31 17:25:58 by malexand         ###   ########.fr       */
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

	char			***map;

	int				h;
	int				w;
	int				init;
}				t_env;

/*
** Func events:
*/

int				loop(t_env *e);
int				press_destroy(t_env *e);
int				key_press(int keycode, t_env *e);
int				key_release(int keycode, t_env *e);
int				mouse_button(int button, int x, int y, t_env *e);
int				mouse_motion(int x, int y, t_env *e);

/*
** Func img:
*/

int				put_img(t_env *e);

/*
** Func env:
*/

char			***get_map(t_env *e, char *file);
t_env			*init_env(int w, int h, char *filename);

#endif
