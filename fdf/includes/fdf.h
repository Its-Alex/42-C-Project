/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:12:25 by malexand          #+#    #+#             */
/*   Updated: 2016/11/25 15:21:50 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/libmlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <errno.h>

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

	int			heigth;
	int			width;

	t_point		*point;
}				t_params;

char			*parse_file(const char *file_name);
void			error(int error, int perror, char *str);

#endif
