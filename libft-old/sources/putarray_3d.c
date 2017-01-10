/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putarray_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:40:45 by malexand          #+#    #+#             */
/*   Updated: 2016/11/24 15:53:48 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
