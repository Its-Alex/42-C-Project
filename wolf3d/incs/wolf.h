/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:50:59 by malexand          #+#    #+#             */
/*   Updated: 2017/02/16 15:32:21 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <mlx.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>
# include <math.h>
# include "../libft/incs/libft.h"
# include "keys.h"

# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

typedef struct	s_persp
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;

	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;

	double			sidedistx;
	double			sidedisty;

	double			deltadistx;
	double			deltadisty;

	double			perpwalldist;

	int				stepx;
	int				stepy;
	int				side;

	int				lineheight;

	int				drawstart;
	int				drawend;

	int				hit;

	int				mapx;
	int				mapy;
}				t_persp;

typedef struct	s_key
{
	int			run;
	int			turn;
}				t_key;

typedef struct	s_map
{
	char			***mapget;
	int				mapgen[50][50];

	int				line;
	int				column;
}				t_map;

typedef struct	s_img
{
	void			*img;
	char			*addr;

	int				bpp;
	int				size_l;
	int				endian;

	int				x;
	int				y;
	char			opacity;
}				t_img;

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	t_img			*view;
	t_img			*mmap;
	t_img			*wood;

	t_persp			*persp;
	t_map			*map;
	t_key			key;

	int				init;
	int				width;
	int				heigth;
}				t_env;

void			key_move(t_env *e);
void			free_tab(char ***str);

/*
** Funcs math:
*/

void			rotate(double *x, double *y, double coef);

/*
**   Funcs graph:
*/

void			ray_casting(t_env *e);
void			minimap(t_env *e);
void			mmap_ray(t_env *e, int x, int y);
int				fps(t_env *e);
t_img			*swap_texture(t_img *img);

/*
** Funcs gen maps:
*/

void			get_randmap(t_map **map);
void			atoi_map(t_map **map);
int				check_format(char *str, int count, int nb_elem);
void			get_spawn(t_env *e, t_map *map);
void			gen_spawn(t_env *e, t_map *map);

/*
** Funcs events:
*/

int				loop(t_env *e);
int				press_destroy(t_env *e);
int				key_press(int keycode, t_env *e);
int				key_release(int keycode, t_env *e);
int				mouse_button(int button, int x, int y, t_env *e);
int				mouse_motion(int x, int y, t_env *e);

/*
** Funcs imgs:
*/

int				put_img(t_env *e);
void			mlx_pixel_put_img(unsigned int color, t_img *img, int x, int y);
void			draw_line(t_env *e, int x, int start,
					int stop, unsigned int color, int texture_x);

/*
** Funcs env:
*/

char			***get_map(t_map **map, char *file);
t_env			*init_env(char *filename);

#endif
