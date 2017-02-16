/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:40:13 by malexand          #+#    #+#             */
/*   Updated: 2016/12/08 12:02:39 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		check_str(char *str)
{
	if (str == NULL)
		return (-1);
	if (str[0] == '\0')
		return (-1);
	return (0);
}

static	int		check_format(char *str, int count, int nb_elem)
{
	int		save;

	save = 0;
	while (str[count] != '\0')
	{
		if (str[count] != ' ' && str[count] != '\n')
		{
			while (str[count] != ' ' && str[count] != '\n')
				count++;
			nb_elem++;
		}
		if (str[count] == '\n')
		{
			if (save == 0)
				save = nb_elem;
			else
			{
				if (save != nb_elem)
					return (-1);
			}
			nb_elem = 0;
		}
		count++;
	}
	return (0);
}

static	void	check_fnumber(char *str, int *count)
{
	if (str[*count] == '-' || str[*count] == '+')
		*count = *count + 1;
	while (str[*count] <= '9' && str[*count] >= '0')
		*count = *count + 1;
	if (str[*count] == ',')
		*count = *count + 1;
	while ((str[*count] >= '0' && str[*count] <= '9') ||
			(str[*count] >= 'a' && str[*count] <= 'f') ||
			(str[*count] >= 'A' && str[*count] <= 'F') || str[*count] == 'x')
		*count = *count + 1;
}

static	int		check_fnumbers(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
	{
		while (str[count] == ' ')
			count++;
		while (str[count] != ' ')
		{
			check_fnumber(str, &count);
			if (str[count] == '\n')
			{
				count++;
				check_fnumber(str, &count);
			}
			if (str[count] == '\0')
				return (0);
			if (str[count] != ' ')
				return (-1);
		}
	}
	return (0);
}

void			check(char *str)
{
	if (check_str(str) == -1)
		error(1, 0, "Bad format!");
	if (check_format(str, 0, 0) == -1)
		error(1, 0, "Bad format lenght of the lines must be the same!");
	if (check_fnumbers(str) == -1)
		error(1, 0, "Bad format must be [nombre,color]!");
}
