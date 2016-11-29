/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:17:39 by malexand          #+#    #+#             */
/*   Updated: 2016/11/29 18:01:35 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libmlx.h"
#include "../../includes/libft.h"

t_params		*init_mlx(t_params *params, char **av, int w, int h)
{
	if ((params = (t_params *)malloc(sizeof(t_params))) == NULL)
		return (NULL);
	params->mlx = mlx_init();
	params->win = mlx_new_window(params->mlx, 500, 500, "fdf");
	params->width = w;
	params->heigth = h;
	params->av = av;
	return (params);
}

t_img			*init_img(t_params *params)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(*img))))
	{
		ft_putstr_color("Error ", RED);
		ft_putstr(": create img failed");
		exit(-1);
	}
	img->img = mlx_new_image(params->mlx, params->width, params->heigth);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_l),
		&(img->endian));
	return (img);
}
