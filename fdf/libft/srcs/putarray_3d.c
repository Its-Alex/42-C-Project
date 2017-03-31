/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putarray_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:40:45 by malexand          #+#    #+#             */
/*   Updated: 2017/03/31 17:57:29 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	putarray_3d(char ***array)
{
	int		line;
	int		column;

	line = 0;
	column = 0;
	while (array[line])
	{
		column = 0;
		while (array[line][column])
		{
			ft_putstr(array[line][column]);
			ft_putstr(" ");
			column++;
		}
		ft_putendl("");
		line++;
	}
}
