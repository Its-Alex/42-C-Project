/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:25:25 by malexand          #+#    #+#             */
/*   Updated: 2016/11/10 15:25:27 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/lib.h"

int 	main(int argc, char const **argv)
{
	if (argc > 2	 || argc == 1)
		ft_putstr("Error you must use only one arguments.\n");
	else
	{
		ft_check_tetraminos(argv[1]);
	}
	return (0);
}