/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:50:59 by malexand          #+#    #+#             */
/*   Updated: 2017/02/22 17:08:51 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <mlx.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>
# include <math.h>
# include <dirent.h>
# include "../libft/incs/libft.h"
# include "keys.h"

# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

typedef struct dirent	t_dir;

typedef struct	s_persp
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;

	double			camerax;
	double			xraypos;
	double			yraypos;
	double			xraydir;
	double			yraydir;

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
	int			strafe;
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
}				t_img;

typedef struct	s_draw
{
	int				x;
	int				x_tex;
	int				start;
	int				stop;
}				t_draw;

typedef struct	s_mmap
{
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				content;
}				t_mmap;

typedef struct	s_env
{
	void			*mlx;
	void			*win;

	t_img			*view;
	t_img			*mmap;
	t_img			*wall;
	t_img			*door;
	t_img			*sky;

	t_persp			*persp;
	t_map			*map;
	t_key			key;

	char			*filename;

	int				init;
	int				width;
	int				height;
}				t_env;

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
void			floor_up(t_env *e);
void			floor_down(t_env *e);
void			check_floor(t_env *e);

/*
** Funcs gen maps:
*/

t_map			*init_map(t_env *e, char *filename);
void			change_map(t_env *e, char *filename);
void			get_randmap(t_map **map);
void			atoi_map(t_map **map);
int				check_format(char *str, int count, int nb_elem);
void			get_spawn(t_env *e, t_map *map);
void			gen_spawn(t_env *e, t_map *map);
void			check_gates(t_map *map);

/*
** Funcs events:
*/

int				loop(t_env *e);
int				press_destroy(t_env *e);
int				key_press(int keycode, t_env *e);
int				key_release(int keycode, t_env *e);
void			key_move(t_env *e, double speed);

/*
** Funcs imgs:
*/

int				put_img(t_env *e);
void			mlx_ppi(unsigned int color, t_img *img, int x, int y);
t_img			*init_texture(t_env *e, char *name);
t_img			*init_img(t_env *e, int width, int height);
void			draw_line(t_env *e, t_draw draw);
int				get_color(t_img *img, int x, int y);

/*
** Funcs env:
*/

char			***get_map(t_map **map, char *file);
t_env			*init_env(char *filename);

/*
** Funcs utils:
*/

void			free_tab(char ***str);

#endif
