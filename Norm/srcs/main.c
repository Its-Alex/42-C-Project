/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 11:51:42 by alex              #+#    #+#             */
/*   Updated: 2016/04/03 18:30:40 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/tool.h"

int     main(int argc, char **argv)
{
	char tab[BUFFER_SIZE];
	int  i;

	i = 1;
	(void)argv;
	if (argc < 2)
	{
		flx_fprintf(1, "Error: usage: %s [file]\n", argv[0]);
	}
	else
	{
		while (i < argc)
		{
			if (readfile(tab, argv[i]) < 0)
				return (-1);
			check_array(tab, argv[i]);
			i++;
		}
	}
	return(0);
}
