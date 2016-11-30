/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:40:13 by malexand          #+#    #+#             */
/*   Updated: 2016/11/30 18:44:34 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	int		check_format(char *str)
{
	int		line;
	int		count;
	int		nb_line;

	line = 0;
	count = 0;
	nb_line = 0;
	while (str[count] != '\0')
	{
		if (str[count] == '\n' && str[count + 1] != '\0')
		{
			if (line == 0)
				line = count;
			else if (((count - nb_line) % line) != 0)
				return (-1);
			nb_line++;
		}
		count++;
	}
	return (0);
}

static	int		check_fnumber(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
	{
		while (str[count] == ' ')
			count++;
		while (str[count] != ' ')
		{
			while (str[count] <= '9' && str[count] >= '0')
				count++;
			if (str[count] == ',')
				count++;
			while ((str[count] >= '0' && str[count] <= '9') ||
					(str[count] >= 'A' && str[count] <= 'F'))
				count++;
			if (str[count] == '\n')
			{
				count++;
				while (str[count] <= '9' && str[count] >= '0')
					count++;
				if (str[count] == ',')
					count++;
				while ((str[count] >= '0' && str[count] <= '9') ||
						(str[count] >= 'A' && str[count] <= 'F'))
					count++;
			}
			if (str[count] != ' ')
				return (-1);
		}
	}
	return (1);
}

void			check(char *str)
{
	if (check_format(str) == -1)
		error(1, 0, "Bad format lenght of the lines must be the same!");
	if (check_fnumber(str) == -1)
		error(1, 0, "Bad format must be [nombre,color]!");
}
