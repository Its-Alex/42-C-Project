/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 17:18:43 by malexand          #+#    #+#             */
/*   Updated: 2015/07/19 22:44:32 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_column(char **argv, int x, char k);
int		ft_check_bloc(char **argv, char k, int y, int x);
int		ft_check_line(char **argv, int y, char k);

int ft_check(char **argv)
{
	int y;
	int x;

	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			if (ft_check_column(argv, x, argv[y][x]) 
				&& ft_check_line(argv, y, argv[y][x]) 
				&& ft_check_bloc(argv, argv[y][x], y, x)) 
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int		ft_scan(char **tab1, char **tab2)
{
	int x;
	int y;

	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			if (tab1[y][x] != tab2[y][x])
				return (0);
		}
	}
	return (1);
}



char	**ft_str_strdup(char **argv)
{
	int x;
	int y;
	char **str;

	y = 0;
	str = (char**)malloc(sizeof(*str) * 9);
	while ( y <= 9)
	{
		str[y] = (char*)malloc(sizeof(**str) * 9);
		y++;
	}
	y = 0;
	while (y <= 8)
	{
		x = 0;
		while (x <= 8)
		{
			str[y][x] = argv[y + 1][x];
			x++;
		}
		str[y][x] = '\0';
		y++;
	}
	return (str);
}
