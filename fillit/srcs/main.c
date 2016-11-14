/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:25:25 by malexand          #+#    #+#             */
/*   Updated: 2016/11/11 14:59:03 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/lib.h"

int		main(int argc, char const **argv)
{
	char **tetri;

	while (1)
	{
		if (argc > 2 || argc == 1)
			ft_putstr("Error use ./fillit file\n");
		else
		{
			tetri = ft_split_tetri(argv[1]);
			if (tetri)
			{
				ft_free_array(tetri);
			}
			else
				ft_putstr("error\n");
		}
	}
	return (0);
}
