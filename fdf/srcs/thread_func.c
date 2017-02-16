/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:02:21 by malexand          #+#    #+#             */
/*   Updated: 2016/12/15 11:46:33 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		get_size(t_mlx *mlx, t_put *p)
{
	p->line = 0;
	p->column = 0;
	p->mline = 0;
	while (mlx->point[p->mline])
	{
		p->mcolumn = 0;
		while (mlx->point[p->mline][p->mcolumn])
			p->mcolumn++;
		p->mline++;
	}
}

void			*p_put_img_hg(void *arg)
{
	t_mlx	*mlx;
	t_put	p;

	mlx = arg;
	get_size(mlx, &p);
	while (mlx->point[p.line] && p.line < p.mline / 2)
	{
		p.column = 0;
		while (mlx->point[p.line][p.column] && p.column < p.mcolumn / 2)
		{
			if (mlx->point[p.line + 1])
				mlx_put_line(mlx, mlx->point[p.line][p.column],
					mlx->point[p.line + 1][p.column]);
			if (mlx->point[p.line][p.column + 1])
				mlx_put_line(mlx, mlx->point[p.line][p.column],
					mlx->point[p.line][p.column + 1]);
			if (!mlx->point[p.line + 1] && !mlx->point[p.line][p.column + 1])
				mlx_put_line(mlx, mlx->point[p.line][p.column],
					mlx->point[p.line][p.column]);
			p.column++;
		}
		p.line++;
	}
	pthread_exit(NULL);
}

void			*p_put_img_hd(void *arg)
{
	t_mlx	*mlx;
	t_put	p;

	mlx = arg;
	get_size(mlx, &p);
	p.line = p.mline / 2;
	while (mlx->point[p.line])
	{
		p.column = 0;
		while (mlx->point[p.line][p.column] && p.column < p.mcolumn / 2)
		{
			if (mlx->point[p.line + 1])
				mlx_put_line(mlx, mlx->point[p.line][p.column],
					mlx->point[p.line + 1][p.column]);
			if (mlx->point[p.line][p.column + 1])
				mlx_put_line(mlx, mlx->point[p.line][p.column],
					mlx->point[p.line][p.column + 1]);
			if (!mlx->point[p.line + 1] && !mlx->point[p.line][p.column + 1])
				mlx_put_line(mlx, mlx->point[p.line][p.column],
					mlx->point[p.line][p.column]);
			p.column++;
		}
		p.line++;
	}
	pthread_exit(NULL);
}

void			*p_put_img_bg(void *arg)
{
	t_mlx	*mlx;
	t_put	p;

	mlx = arg;
	get_size(mlx, &p);
	while (mlx->point[p.line] && p.line < p.mline / 2)
	{
		p.column = p.mcolumn / 2;
		while (mlx->point[p.line][p.column])
		{
			if (mlx->point[p.line + 1])
				mlx_put_line(mlx, mlx->point[p.line][p.column],
					mlx->point[p.line + 1][p.column]);
			if (mlx->point[p.line][p.column + 1])
				mlx_put_line(mlx, mlx->point[p.line][p.column],
					mlx->point[p.line][p.column + 1]);
			if (!mlx->point[p.line + 1] && !mlx->point[p.line][p.column + 1])
				mlx_put_line(mlx, mlx->point[p.line][p.column],
					mlx->point[p.line][p.column]);
			p.column++;
		}
		p.line++;
	}
	pthread_exit(NULL);
}

void			*p_put_img_bd(void *arg)
{
	t_mlx	*mlx;
	t_put	p;

	mlx = arg;
	get_size(mlx, &p);
	p.line = p.mline / 2;
	while (mlx->point[p.line])
	{
		p.column = p.mcolumn / 2;
		while (mlx->point[p.line][p.column])
		{
			if (mlx->point[p.line + 1])
				mlx_put_line(mlx, mlx->point[p.line][p.column],
					mlx->point[p.line + 1][p.column]);
			if (mlx->point[p.line][p.column + 1])
				mlx_put_line(mlx, mlx->point[p.line][p.column],
					mlx->point[p.line][p.column + 1]);
			if (!mlx->point[p.line + 1] && !mlx->point[p.line][p.column + 1])
				mlx_put_line(mlx, mlx->point[p.line][p.column],
					mlx->point[p.line][p.column]);
			p.column++;
		}
		p.line++;
	}
	pthread_exit(NULL);
}
